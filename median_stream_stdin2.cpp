// Indy Research Labs Problem
// Kishavan Bhola
// 2016-03-26

#include "median_structures3.hpp"

int main(int argc, char** argv) {
  int k;
  // this uses a fixed-size stack-allocated array with insertions via binary
  // search and lots of right-shifting. I would expect this to be slower than
  // the asymptotically optimal Min-Max Heap Solution

  kbhola::Solution2 soln; 
  // Note this is not safe code for reading general input
  while(scanf("%d", &k) == 1 ) {
    soln.process(k);
  }
  
  return 0;
}
