#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int guess(int num) {
  static const int pick = 3;
  if (num > pick) {
    return -1;
  } else if (num < pick) {
    return 1;
  }
  return 0;
}

int main() {
  int n = 10;
  int start = 1;
  int end = n;
  while (start <= end) {
    int mid = start + (int)((end - start) / 2);
    if (guess(mid) == 0) {
      cout << mid << endl;
      break;
    } else if (guess(mid) < 0) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  cout << -1 << endl;
  return 0;
}