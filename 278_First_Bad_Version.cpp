#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool isBadVersion(int version) {
  static const int bad = 9;
  return (version >= bad);
}

int main() {
  int n = 10;
  int start = 1;
  int end = n;
  while (start <= end) {
    int mid = start + (int)((end - start) / 2);
    if (!isBadVersion(mid - 1) && isBadVersion(mid)) {
      cout << mid << endl;
      break;
    } else if (isBadVersion(mid)) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  cout << -1 << endl;
  return 0;
}