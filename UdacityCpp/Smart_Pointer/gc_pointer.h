//
// Created by Ahsan Ghani on 2022-10-26.
//
#include "gc_details.h"
#include "gc_iterator.h"
#include <cstdlib>
#include <iostream>
#include <list>
#include <typeinfo>

template <class T, int size = 0> class Pointer {
private:
  static std::list<PtrDetails<T>> ref_countainer;
  T *addr;
  bool is_array;
  unsigned array_size;
  static bool first;
  typename std::list<PtrDetails<T>>::iterator findPtrInfo(T *ptr);

public:
  typedef Iter<T> GCiterator;
  Pointer() { Pointer(NULL); }
  Pointer(T *);
  Pointer(const Pointer &);
  ~Pointer();
  static bool collect();
  T *operator=(T *t);
  Pointer &operator=(Pointer &rv);
  T &operator*() { return *addr; }
  T *operator->() { return addr; }
  T &operator[](int i) { return addr[i]; }
  operator T *() { return addr; }
  Iter<T> begin() {
    int _size;
    if (is_array)
      _size = array_size;
    else
      _size = 1;
    return Iter<T>(addr, addr, addr + _size);
  }
  Iter<T> end() {
    int _size;
    if (is_array)
      _size = array_size;
    else
      _size = 1;
    return Iter<T>(addr + _size, addr, addr + _size);
  }
  static int refContainerSize() { return ref_countainer.size(); }
  static void showlist();
  static void shutdown();
};

template <class T, int size>
std::list<PtrDetails<T>> Pointer<T, size>::ref_countainer;
template <class T, int size> bool Pointer<T, size>::first = true;

template <class T, int size> Pointer<T, size>::Pointer(T *t) {
  if (first)
    atexit(shutdown);
  first = false;
  typename std::list<PtrDetails<T>>::iterator p;
  p = findPtrInfo(t);
  if (p != ref_countainer.end())
    p->ref_count++; // increment ref count
  else {
    PtrDetails<T> gcObj(t, size);
    ref_countainer.push_front(gcObj); // insert before the head of the list
  }

  addr = t;
  array_size = size;
  if (size > 0)
    is_array = true;
  else
    is_array = false;
#ifdef DISPLAY
  std::cout << "Constructing Pointer (w/ garbage collector).";
  if (is_array)
    std::cout << " Size is " << array_size << std::endl;
  else
    std::cout << std::endl;
#endif
}

template <class T, int size> Pointer<T, size>::Pointer(const Pointer &ob) {
  typename std::list<PtrDetails<T>>::iterator p;
  p = findPtrInfo(ob.addr);
  p->ref_count++;

  addr = ob.addr;
  array_size = ob.array_size;
  if (array_size > 0)
    is_array = true;
  else
    is_array = false;

#ifdef DISPLAY
  std::cout << "Consturcting copy.";
  if (is_array)
    std::cout << " Size is " << array_size << endl;
  else
    std::cout << std::endl;
#endif
}

template <class T, int size> Pointer<T, size>::~Pointer() {
  typename std::list<PtrDetails<T>>::iterator p;

  p = findPtrInfo(addr);
  if (p->ref_count)
    p->ref_count--; // decrement ref_count

#ifdef DISPLAY
  std::cout "Pointer (w/ garbage collection) going out of scope.\n";
#endif
  collect();
}

template <class T, int size> bool Pointer<T, size>::collect() {
  bool mem_freed = false;

#ifdef DISPLAY
  std::cout << "Before garbage collection for ";
  showlist();
#endif

  typename std::list<PtrDetails<T>>::iterator p;
  do {
    for (p = ref_countainer.begin(); p != ref_countainer.end(); p++) {
      if (p->ref_count > 0)
        continue;

      mem_freed = true;

      ref_countainer.remove(*p);

      if (p->mem_ptr) {
        if (p->is_array) {
#ifdef DISPLAY
          std::cout << "Deleting array of size " << p->array_size << std::endl;
#endif
          delete[] p->mem_ptr;
        } else {
#ifdef DISPLAY
          std::cout << "Deleting: " << *(T *)p->mem_ptr << std::endl;
#endif
          delete p->mem_ptr;
        }
      }

      break;
    }

  } while (p != ref_countainer.end());

#ifdef DISPLAY
  std::cout << "After garbage collection for ";
  showlist();
#endif

  return mem_freed;
}

template <class T, int size> T *Pointer<T, size>::operator=(T *t) {
  typename std::list<PtrDetails<T>>::iterator p;
  p = findPtrInfo(addr);
  p->ref_count--;
  p = findPtrInfo(t);
  if (p != ref_countainer.end())
    p->ref_count++;
  else {
    PtrDetails<T> gcObj(t, size);
    ref_countainer.push_front(gcObj);
  }

  addr = t;

  return t;
}

template <class T, int size>
Pointer<T, size> &Pointer<T, size>::operator=(Pointer &rv) {
  typename std::list<PtrDetails<T>>::iterator p;
  p = findPtrInfo(addr);
  p->ref_count--;
  p = findPtrInfo(rv.addr);
  p->ref_count++; // increment ref count

  addr = rv.addr;

  return rv;
}

template <class T, int size> void Pointer<T, size>::showlist() {
  typename std::list<PtrDetails<T>>::iterator p;
  std::cout << "ref_countainer<" << typeid(T).name() << ", " << size << ">:\n";
  std::cout << "memPtr refcount value\n ";
  if (ref_countainer.begin() == ref_countainer.end()) {
    std::cout << " Container is empty!\n\n ";
  }
  for (p = ref_countainer.begin(); p != ref_countainer.end(); p++) {
    std::cout << "[" << (void *)p->memPtr << "]"
              << " " << p->refcount << " ";
    if (p->memPtr)
      std::cout << " " << *p->memPtr;
    else
      std::cout << "---";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}