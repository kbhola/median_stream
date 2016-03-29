// Indy Research Labs Problem
// Kishavan Bhola
// 2016-03-26

#include "median_structures_stl.hpp"
// This solution uses std::vector with sort as a comparison
// The only diffence between this and solution 3
// is that this solution reserves a maximum size
// to test the efficiency of such a thing

int main(int argc, char** argv) {
  int k;
  const size_t MX = 10*1000*1000; // 10M
  Solution3 soln(MX);
    
  // Note this is not safe code for reading general input
  while(scanf("%d", &k) == 1 ) {
    soln.process(k);
  }
  
  return 0;
}
