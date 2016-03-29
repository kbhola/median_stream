// Second version of Median Stream Problem for Indy Research
// 2016-03-21
// Kishavan Bhola

#include "median_structures.hpp"

using namespace kbhola;
int main(int argc, char** argv) {  
    puts("Hello World");
    Array<int, 5> arr;

    const size_t MX = 10*1000*1000; // 10 million
    /**
       10 Million integers will cause a stack overflow
       unless compiled with flags to increase stack size.
       Sample Command:

       cc -Wl,-stack_size -Wl,0x3000000 -o median_stream2 median_stream2.cpp
     **/
    Array<int, MX> arr2;

    printf("%ld\n", arr2.sz());

    for(size_t i = 0; i < arr2.sz(); ++i) {
      arr2[i] = i;
    }
    /**
    for(size_t i = 0; i < arr2.sz()/100; ++i) {
      printf("%d, ", arr2[i]);
    }
    **/

    /**
    MyVec<int, 3>  arr3;
    printf("%ld\n", arr3.size());

    arr3[3] = 1;
    **/
    
    /**
    printf("%ld \n", arr.sz());
    
    for(size_t i = 0; i < arr.sz(); ++i)
      arr[i] = i;

    for(size_t i = 0; i < arr.sz(); ++i)
      printf("%d \n", arr[i]);
    **/
    return 0;
}
