// Fourth Version of Median Stream Problem for Indy Research
// 2016-03-22
// Kishavan Bhola

#include "median_structures3.hpp"

using namespace kbhola;

int main(int argc, char** argv) {
  
  Solution1 soln; // see median_structures3.hpp
  
  for(int i = 1; i < argc; ++i) {
    soln.process(atoi(argv[i]));
  }
  
}
