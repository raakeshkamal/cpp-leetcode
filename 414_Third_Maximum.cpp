#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void sort_vec(vector<int> &nums) {

  for (int i = 1; i < nums.size(); i++) {
    int key = nums[i];

    int j = i - 1;
    while (j >= 0 && key >= nums[j]) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = key;
  }
}

void print_1d_vector(vector<int> arr) {
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums = {2, 2, 3, 1};
  // too slow
  // sort_vec(nums);
  // print_1d_vector(nums);
  // int max = nums[0];
  // int ctr = 0;
  // for (auto i : nums) {
  //   if (i < max) {
  //     max = i;
  //     ctr++;
  //   }
  //   if (ctr > 1) {
  //     break;
  //   }
  // }
  // if (ctr < 2) {
  //   max = nums[0];
  // }
  long long max1 = INT64_MIN;
  long long max2 = INT64_MIN;
  long long max3 = INT64_MIN;
  for (auto i : nums) {
    if (i == max1 || i == max2 || i == max3) {
      continue;
    }
    if (i > max1) {
      max3 = max2;
      max2 = max1;
      max1 = i;
    } else if (i > max2) {
      max3 = max2;
      max2 = i;
    } else if (i > max3) {
      max3 = i;
    }
  }
  int max = (int)max1;
  if (max3 != INT64_MIN) {
    max = (int)max3;
  }

  cout << max << endl;
  return 0;
}