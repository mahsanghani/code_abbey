//
// Created by Ahsan Ghani on 2022-10-04.
//
#include <assert.h>
#include <iostream>

using namespace std;

template <class _Tc> class List {
public:
  List() : head_(nullptr), tail_(nullptr) {}
  ~List();
  void PushFront(_Tc);
  void PushBack(_Tc);
  _Tc PopFront();
  _Tc PopBack();
  int Size() const;
  bool Empty() const { return (head_ == nullptr); }
  void Print() const;

private:
  struct Node {
    _Tc val;
    Node *prev;
    Node *next;
    Node(_Tc val, Node *prev, Node *next) : val(val), prev(prev), next(next) {}
  };

  Node *head_;
  Node *tail_;
};

template <class _Tc> List<_Tc>::~List() {
  while (head_) {
    Node *current(head_);
    head_ = head_->next;
    delete current;
  }
}

template <class _Tc> void List<_Tc>::PushFront(_Tc val) {
  Node *front_node = new Node(val, nullptr, head_);
  if (tail_ == nullptr) {
    tail_ = front_node;
    head_ = front_node;
  } else {
    head_->prev = front_node;
    head_ = front_node;
  }
}

template <class _Tc> void List<_Tc>::PushBack(_Tc val) {
  Node *back_node = new Node(val, tail_, nullptr);
  if (head_ == nullptr) {
    head_ = back_node;
    tail_ = back_node;
  } else {
    tail_->next = back_node;
    tail_ = back_node;
  }
}

template <class _Tc> _Tc List<_Tc>::PopFront() {
  if (this->Empty())
    throw("Cannot List::PopFront() when List::Empty() is true");

  Node *temp(head_);
  _Tc val = head_->val;
  head_ = head_->next;
  if (head_)
    head_->prev = nullptr;
  else
    tail_ = nullptr;

  delete temp;
  return val;
}

template <class _Tc> _Tc List<_Tc>::PopBack() {
  if (this->Empty())
    throw("Cannot List::PopBack() when List::Empty() is true");

  Node *temp(tail_);
  _Tc val = tail_->val;
  tail_ = tail_->prev;
  if (tail_)
    tail_->next = nullptr;
  else
    head_ = nullptr;

  delete temp;
  return val;
}

template <class _Tc> int List<_Tc>::Size() const {
  int size = 0;
  Node *current(head_);
  while (current) {
    size++;
    current = current->next;
  }
  return size;
}

template <class _Tc> void List<_Tc>::Print() const {
  Node *current(head_);
  while (current) {
    std::cout << "list current val = " << current->val << std::endl;
    current = current->next;
  }
}

int main() {
  List<int> list1;
  list1.PushBack(9);
  assert(list1.Size() == 1);

  List<int> list2;
  list2.PushFront(9);
  list2.PushBack(10);
  assert(list2.Size() == 2);
  assert(list2.PopBack() == 10);
  assert(list2.PopFront() == 9);
  assert(list2.Size() == 0);
  return 0;
}