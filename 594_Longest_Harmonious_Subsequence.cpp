#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void sort_vec(vector<int> &nums) {

  for (int i = 1; i < nums.size(); i++) {
    int key = nums[i];

    int j = i - 1;
    while (j >= 0 && key <= nums[j]) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = key;
  }
}

void add_num_to_hash_map(unordered_map<int, int> &hash_map,
                         vector<int> &unique_elems, int num) {
  if (hash_map.find(num) == hash_map.end()) {
    hash_map[num] = 1;
    unique_elems.push_back(num);
  } else {
    hash_map[num]++;
  }
}

void get_first_last_pos(vector<int> &nums, int num, int &first, int &last) {
  first = -1;
  last = -1;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == num || nums[i] == (num + 1)) {
      if (first == -1) {
        first = i;
      }
      if (last < i) {
        last = i;
      }
    }
  }
}

void print_1d_vector(vector<int> arr) {
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums = {1,2,3,4};
  sort_vec(nums);
  print_1d_vector(nums);
  unordered_map<int, int> hash_map;
  vector<int> unique_elems;
  for (auto i : nums) {
    add_num_to_hash_map(hash_map, unique_elems, i);
  }
  print_1d_vector(unique_elems);

  int max_len = INT32_MIN;
  for (int i = 0; i < unique_elems.size() - 1; i++) {
    if (unique_elems[i + 1] - unique_elems[i] == 1) {
      int first, last;
      get_first_last_pos(nums, unique_elems[i], first, last);
      if ((last - first + 1) > max_len) {
        max_len = last - first + 1;
      }
    }
  }
  if (max_len == INT32_MIN or max_len == 1) {
    max_len = 0;
  }
  cout << max_len << endl;
  return 0;
}