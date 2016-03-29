// Indy Research Labs Problem
// Kishavan Bhola
// 2016-03-26

#include "median_structures_stl.hpp"
// This solution uses std::vector with sort as a comparison


int main(int argc, char** argv) {
  int k;
  
  Solution3 soln;
    
  // Note this is not safe code for reading general input
  while(scanf("%d", &k) == 1 ) {
    soln.process(k);
  }
  
  return 0;
}
