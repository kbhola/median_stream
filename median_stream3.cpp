// Third Version of Median Stream Problem for Indy Research
// 2016-03-21
// Kishavan Bhola

#include "median_structures3.hpp"

using namespace kbhola;

int main(int argc, char** argv) {  
  Solution1 soln; // see median_structures3.hpp
  printf("Enter 'quit' to quit at any point.\n");
  printf("Enter an integer to add to the stream: ");
    char data[64];  
    fgets(data, 64, stdin);
    while (strcmp(data, "quit\n") != 0) {
      soln.process(atoi(data));
      printf("Enter another integer to add to the stream: ");
      fgets(data, 64, stdin);
    }
}
