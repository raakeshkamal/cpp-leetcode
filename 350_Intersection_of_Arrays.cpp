#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void add_num_to_hash_map(unordered_map<int, int> &hash_map, int num) {
  if (hash_map.find(num) == hash_map.end()) {
    hash_map[num] = 1;
  } else {
    hash_map[num]++;
  }
}

void print_1d_vector(vector<int> arr) {
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2};
  vector<int> res;
  unordered_map<int, int> hash_map1;
  unordered_map<int, int> hash_map2;
  for (auto i : nums1) {
    add_num_to_hash_map(hash_map1, i);
  }
  for (auto i : nums2) {
    add_num_to_hash_map(hash_map2, i);
  }
  if(hash_map1.size() > hash_map2.size()){
    unordered_map<int, int> temp = hash_map2;
    hash_map2 = hash_map1;
    hash_map1 = temp;
  }
  for (auto it = hash_map1.begin();it!= hash_map1.end();it++) {
    if (hash_map2.find(it->first) != hash_map1.end()) {
      int min = it->second < hash_map2[it->first] ? it->second : hash_map2[it->first];
      for(int i=0;i<min;i++){
        res.push_back(it->first);
      }
    }
  }
  print_1d_vector(res);
  return 0;
}