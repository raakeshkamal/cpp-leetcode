#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n = 100;
  int i = 0;
  bool res = false;
  while (true) {
    if ((i * i) < n) {
      i++;
    } else if ((i * i) > n) {
      break;
    } else {
      res = true;
      break;
    }
  }
  cout << (res ? "True" : "False") << endl;
  return 0;
}