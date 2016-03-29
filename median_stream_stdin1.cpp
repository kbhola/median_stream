// Indy Research Labs Problem
// Kishavan Bhola
// 2016-03-26

#include "median_structures3.hpp"

int main(int argc, char** argv) {
  int k;

  // This is my Min/Max Heap solution
  kbhola::Solution1 soln;

  // Note this is not safe code for reading general input
  while(scanf("%d", &k) == 1 ) {
    soln.process(k);
  }
  
  return 0;
}
