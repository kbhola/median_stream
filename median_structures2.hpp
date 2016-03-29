//
// median_structures2.hpp
// median_stream
// 
// Median Structures 2
// 2016-03-21
// Kishavan Bhola
//
// This is building on the more abstract data structures in Median Structures 2

#include "median_structures.hpp"

namespace kbhola {
  
  // Sorted Array on my stack-allocated array
  // Insertions via Binary Search
  template<typename T, size_t N>
  class SortedArray {
    Array<T, N> arr;
    size_t szz;

    void right_shift(size_t idx) {
      // shifts all elements 1 to the right, starting from idx
      // assumes capacity N is large enough (no bounds checking!)
      // this leaves arr[idx] free to be overwritten
      T prev = arr[idx];
      ++idx;
      while (idx <= szz && idx < N) {
          T cur = arr[idx];
          arr[idx] = prev;
          prev = cur;
          ++idx;
      }    
    }

    /**
       Generic binary search -- returns the index in the array arr
       that el should be inserted into, assuming ascending order
       & assuming arr is sorted
    **/
    size_t binary_search(T el) {
      if (szz == 0) return 0;

      size_t left_idx = 0;
      size_t right_idx = szz - 1;

       T left = arr[left_idx];
       T right = arr[right_idx];

      if (el <= left)
	return left_idx;
      else if (el >= right) // double check
	return right_idx + 1;


      size_t mid_idx = (left_idx + right_idx)/2;
      while (left_idx + 1 < right_idx) {
           T mid = arr[mid_idx];
          if (el == mid)
              return mid_idx;
          else if (el < mid)
              right_idx = mid_idx;
          else
              left_idx = mid_idx;
    
          left = arr[left_idx];
          right = arr[right_idx];
          mid_idx = (left_idx + right_idx)/2;
      }
      T mid = arr[mid_idx];
      if (el <= mid)
          return mid_idx;
      else
          return mid_idx + 1;
    }
        
  public:
    SortedArray() : szz(0) {}
    T& operator[](size_t idx) { return arr[idx]; }
    size_t cap() const { return N; } // differentiating capacity from size
    size_t sz() const {return szz; }

    void try_insert (T el) {
      if (szz < N) {
          if (szz == 0) {
              arr[0] = el;
          }
          else {
              size_t idx = binary_search(el);
              right_shift(idx);
              arr[idx] = el;
          }
          ++szz;
      }
      else if (el < arr[szz -1 ]) {
	
          --szz;  // will, in effect, throw away the last element

          size_t idx = binary_search(el);
          right_shift(idx);
          arr[idx] = el;
          ++szz;
      }
    }

    T last() { return arr[szz -1]; }
    
  };


  bool less_than(int x, int y) {return x < y; }
  bool greater_than(int x, int y) { return x > y; }
}
