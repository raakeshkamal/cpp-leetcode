#include <cmath>
#include <cstdint>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>
using namespace std;

int get_num_bits(int n) {
  int res = 0;
  while (n > 0) {
    n /= 2;
    res++;
  }
  return res;
}

int main() {
  int n = 127;
  n = get_num_bits(n);
  int res = 0;
  for (int i = 0; i < n; i++) {
    res *= 2;
    res++;
  }
  cout << res << endl;
  return 0;
}