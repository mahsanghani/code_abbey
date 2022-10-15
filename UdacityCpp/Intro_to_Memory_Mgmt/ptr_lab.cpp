//
// Created by Ahsan Ghani on 2022-10-15.
//
template <class _Tc> class PtrDetails {
public:
  int ref_count_;
  _Tc *mem_ptr;
  int array_size_;
  PtrDetails(_Tc *obj, int size);
};
// operator== defines a comparison between two objects

template <class _Tc>
bool operator==(const PtrDetails<T> &obj_1, const PtrDetails<T> &obj_2) {
  return (obj_1.array_size_ == obj_2.array_size_ &&
          obj_1.mem_ptr == obj_2.mem_ptr);
}