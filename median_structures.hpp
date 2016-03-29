//
//  median_structures.hpp
//  median_stream
//
// 
//  
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef median_structures_hpp
#define median_structures_hpp

namespace kbhola {

  // My Stack Array Template Wrapper
  // -- to see how much it takes for a stack overflow --
  template<typename T, size_t N>
  class Array {
    T arr[N];    
  public:
    Array() {
        for(size_t i = 0; i < N; ++i)
            arr[i] = T();
    }
    T& operator[](size_t idx) { return arr[idx]; }
    size_t capac() const { return N; } 
  };


  // simple, generic swap function
  template<typename T>
  void swap(T & first, T & second) {
    T temp = first;
    first = second;
    second = temp;
  }

  
  // My Binary Tree Node Implementation
  template<typename T>
  struct Node {
    T val;
    Node * left;
    Node * right;
    Node(T v): val(v), left(NULL), right(NULL) {}
    Node(T v, Node * l, Node * r) : val(v), left(l), right(r) {}
  
    // requiring the type T to have an empty constructor
    Node() : val(), left(NULL), right(NULL) {} 
  };

  /** My own version of a dynamically resizing array
      D is the doubling factor, as a template argument
      I think it's simple and elegant, though admittedly
      operator[] is a bit more inefficient than it needs to be.

      & size() is a bit scary, since its return value could change
      within a for-loop, but other than that, it's clean

      Its only current use is for implementing the abstract Binary Heap below
   **/
  template<typename T, size_t D> 
  class MyVec {
    T * arr;
    size_t sz; // size
    size_t cap; // capacity

    void resize() {      
      size_t new_cap = cap == 0 ? D : D*cap;

      T * new_arr = new T[new_cap];

      //copy old elements over
      for(size_t i = 0; i < sz; ++i) {
          new_arr[i] = arr[i];
      }

      for(size_t i = sz; i < new_cap; ++i) {
	new_arr[i] = T(); // ensure default initialization
      }

      if (arr)
	delete[] arr;
      this -> arr = new_arr;
      this -> cap = new_cap;
    }
    
  public:    
    MyVec(): sz(0), cap(D) { arr = new T[D];}

    T & operator[](const size_t idx) {
      while (idx >= cap) {
          resize();
      }
      if (idx >= sz){
          sz = idx + 1; 
      }
      return arr[idx];
    }
      
    size_t size() const {return sz;}
    size_t capacity() const {return cap;}


    ~MyVec() {
    if (arr) {
          delete[] arr;
        }
    }


  };

  /** My own unique pointer -- not needed for this
  template<typename T>
  class uq_ptr {
    T * ptr;
    uq_ptr(const uq_ptr<T> & rhs); // private copy-constructor
  public:
    uq_ptr(T * p) : ptr(p) {}
    ~uq_ptr() {delete ptr; } 
  
  };
  **/

  
  // Abstraction of Max or Min Binary Heap
  // f is a function pointer that should
  // strongly order all elements of type T
  // e.g., f could represent the less than operator <
  // in which case this would be a min-heap
  // D is the doubling size of the underlying vec
  // 
  template<typename T, bool (*f)(T,T), size_t D>
  class Heap {

    MyVec<T, D> arr; // underlying dynamically resizing array
    // size_t n_els;
    size_t left_child(size_t parent) { return 2*parent + 1; }
    size_t right_child(size_t parent) { return 2*parent + 2; }    
    size_t parent(size_t child) { return (child - 1)/2; } // works for left or right

    // Keep the Heap property, as determined by f(,) !
    void heap_up(size_t papa) {
      if (papa > 0) {
	size_t grandpa = parent(papa);

	if (f(arr[papa], arr[grandpa])) {
	  swap(arr[grandpa], arr[papa]);
	  heap_up(grandpa);
	}
      }      
    }

    // for heaping downwards! Notice the order of child and parent is
    // opposite heap_up's
    void heap_down(size_t start) {
      if (start + 1 < arr.size()) {
	size_t left_c = left_child(start);
	size_t right_c = right_child(start);

	if (left_c < arr.size() && f(arr[left_c], arr[start])) {
	  swap(arr[left_c], arr[start]);
	  heap_down(left_c);
	}
	if(right_c < arr.size() && f(arr[right_c], arr[start])) {
	  swap(arr[right_c], arr[start]);
	  heap_down(right_c);
	}
      }	 
    }
    
  public:
    //    Heap() : arr(), num_els(0) {}
    Heap() : arr() {}

    T& head() {return arr[0];}
    
    size_t num_els() const { return arr.size(); }    
    
    /** push element into heap and ensure that the heap property
     as determined by the function f is still satisfied **/
    void push(T element) {
      const size_t new_guy = num_els();
      arr[new_guy] = element; // this should automatically increment arr.size()
      heap_up(new_guy);
    }

    T swap_head(T new_head) {
      T old_head = arr[0];
      arr[0] = new_head;
      if (f(old_head, new_head)) {
	heap_down(0);	
      } // otherwise the heap property should be preserved

      return old_head;
    }
    
  };

  
}

#endif /* median_structures_hpp */
