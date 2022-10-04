//
// Created by Ahsan Ghani on 2022-10-04.
//
template <class _Tc, int size> bool Pointer<_Tc, size>::collect() {
  bool mem_freed = false;
  std::list<PtrDetails<_Tc>>::iterator p;
  do {
    for (p = refContainer.begin(); p != refContainer.end(); p++) {
      if (p->ref_count > 0) {
        continue;
      }
      mem_freed = true;

      refContainer.remove(*p);

      if (p->mem_ptr) {
        if (p->is_array)
          delete[] p->mem_ptr;
        else
          delete p->mem_ptr;
      }

      break;
    }
  } while (p != refContainer.end());
  return mem_freed;
}

template <class _Tc, int size> Pointer<_Tc, size>::~Pointer() {
  typename list<PtrDetails<_Tc>>::iterator p;
  p = findPtrInfo(addr);
  if (p->ref_count_)
    p->ref_count_--;
  collect();
}