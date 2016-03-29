//
// median_structures3.hpp
// median_stream
// 
// Median Structures 3
// 2016-03-21
// Kishavan Bhola
//
// This implements the Min-Max Heap algorithm for Solving the Indy Research Problem
// Given these are the final layers of abstraction, these are very specific
// but underlying structures are very general.

#include "median_structures2.hpp"


namespace kbhola {
  class Solution1 {

    /**  Templated Binary Heaps with abstract ordering. The heaps are internally
	 represented as dynamically resizing arrays, with the "2" representing the
	 internal capacity factor. See median_structures.hpp and
	 median_structures2.hpp
      **/
    Heap<int, greater_than, 2> max_heap;
    Heap<int, less_than, 2> min_heap;
    SortedArray<int, 10> smallest_ten;
    
  public:
    Solution1(): max_heap(), min_heap(), smallest_ten() {}
    void process(int el) {
      smallest_ten.try_insert(el); // insert element

      size_t mx_els = max_heap.num_els();
      size_t mn_els = min_heap.num_els();
      double median = 0;
      
      if (mx_els + mn_els == 0) {
          max_heap.push(el);
          median = el;

	  printf("Median: ");
	  printf("%lf", median);
	  if (smallest_ten.sz() > 9) {
	    printf(", 10th Smallest: ");
	    printf("%d", smallest_ten.last());
	  }	   
	  printf("\n");         
          return; // bit redundant, but in a hurry
      }

      if (mx_els > mn_els) {
          if (el < max_heap.head()) {
	  // swap max_heap's head with current element
	  el = max_heap.swap_head(el);
	  // now el is what was the previous head of the max heap
	}
	// push this onto the min heap to keep the sizes +/- 1 in difference
	min_heap.push(el);
	median = (max_heap.head() + min_heap.head())/2.0;
      }
      else if (mx_els == mn_els) {
	double cur_median = (max_heap.head() + min_heap.head())/2.0;
	if (el > cur_median) {
	  min_heap.push(el);
	  median = min_heap.head();
	}
	else {
	  max_heap.push(el);
	  median = max_heap.head();
	}	  
      }
      else { // min heap is currently larger
	if (el > min_heap.head()) {
	  // swap min_heap's head with current element
	  el = min_heap.swap_head(el);
	  // now el is what was the previous head of the min heap
	}

	// push onto the max heap to keep sizes within 1 of each other
	max_heap.push(el);
	median = (max_heap.head() + min_heap.head())/2.0;
      }	

      printf("Median: ");
      printf("%lf", median);
      if (smallest_ten.sz() > 9) {
	printf(", 10th Smallest: ");
	printf("%d", smallest_ten.last());
      }
      printf("\n");
      
    }
    
  };
  const size_t MX = 1*1000*1000; // one million

  class Solution2 {
    /** 
	This version of the median stream solution will solve the problem using
	a 10-million integer-sized stack-allocated array where insertions will 
	be done via binary search.  The computationally intensive part will be
	right shifting elements for the binary search.  My expectation is that
	this will be significantly faster than Solution1	
     **/

    SortedArray<int, MX> median_array;
  public:
    
    Solution2(): median_array() {}

    size_t cap() const {return median_array.cap(); }
    size_t sz() const { return median_array.sz(); }
    
    void process(int el) {
      median_array.try_insert(el);    

      const size_t num_els = sz();
      double median = 0.0;
      
      if (num_els  % 2 == 0) {
	median = (static_cast<double>(median_array[num_els/2] +
				      median_array[num_els/2-1])/2.0);
      }
      else { // odd number of elements
	median = static_cast<double>(median_array[num_els/2]);
      }
      
      printf("Median: ");
      printf("%lf", median);

      if (num_els > 9) {
	printf(", 10th Smallest: ");
	printf("%d", median_array[9]);
      }
      printf("\n");            
    }
  };

}

 
