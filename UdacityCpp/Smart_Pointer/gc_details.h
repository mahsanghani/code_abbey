//
// Created by Ahsan Ghani on 2022-10-26.
//
template <class T> class PtrDetails {
public:
  unsigned ref_count;
  T *mem_ptr;

  bool is_array;
  unsigned array_size;
  PtrDetails(T *m_pointer, unsigned mem_size = 0) {
    ref_count = 1;
    mem_ptr = m_pointer;
    if (mem_size != 0)
      is_array = true;
    else
      is_array = false;

    array_size = mem_size;
  }
};

template <class T>
bool operator==(const PtrDetails<T> &ob1, const PtrDetails<T> &ob2) {
  return (ob1.mem_ptr == ob2.mem_ptr);
}