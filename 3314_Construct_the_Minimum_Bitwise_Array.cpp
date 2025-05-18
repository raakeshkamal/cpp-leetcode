#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void print_1d_vector(vector<int> arr) {
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

void add_num_to_hash_map(unordered_map<int, int> &hash_map, int num) {
  if (hash_map.find(num) == hash_map.end()) {
    hash_map[num] = 1;
  } else {
    hash_map[num]++;
  }
}

void add_min_or_of_num(unordered_map<int, int> &hash_map, int num) {
  int key = num | (num + 1);
  if (hash_map.find(key) == hash_map.end()) {
    hash_map[key] = num;
  }
}

int main() {
  vector<int> nums = {11,13,31};
  unordered_map<int, int> hash_map1;
  int max = INT32_MIN;
  for (auto i : nums) {
    if (i > max) {
      max = i;
    }
    add_num_to_hash_map(hash_map1, i);
  }
  unordered_map<int, int> hash_map2;
  for (int i = 1; i <= max; i++) {
    add_min_or_of_num(hash_map2, i);
  }
  vector<int> res;
  for (auto i : nums) {
    if (hash_map2.find(i) == hash_map2.end()) {
      res.push_back(-1);
    } else {
      res.push_back(hash_map2[i]);
    }
  }
  print_1d_vector(res);
  return 0;
}