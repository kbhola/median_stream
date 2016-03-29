#include <vector>


class Solution3 {
  std::vector<int> v;
public:
  Solution3(): v() {}
  Solution3(size_t cap): v() {v.reserve(cap);}

  void process(int k) {
    v.push_back(k);
    std::sort(v.begin(), v.end()); // C++ 11

    double median = 0.0;
    const size_t num_els = v.size();
    if (num_els % 2 == 0) {
      median = (static_cast<double>(v[num_els/2] +
				    v[num_els/2-1])/2.0);    
    }
    else {
      // static cast to double to make the output consistent
      median = static_cast<double>(v[num_els/2]);
    }
  
    printf("Median: ");
    printf("%lf", median);

    if (num_els > 9 ) {
      printf(", 10th Smallest: ");
      printf("%d", v[9]);
    }
    printf("\n");            
  
  }
};
