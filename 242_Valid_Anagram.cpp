#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// string sort_string(string str) {
//   // bubble sort too slow
//   // for (int i = 0; i < str.length() - 1; i++) {
//   //   for (int j = 0; j < str.length() - i - 1; j++) {
//   //     if (str[j] > str[j + 1]) {
//   //       char temp = str[j];
//   //       str[j] = str[j + 1];
//   //       str[j + 1] = temp;
//   //     }
//   //   }
//   // }
//   for (int i = 1; i < str.length(); i++) {
//     char key = str[i];

//     int j = i - 1;
//     while (j >= 0 && key <= str[j]) {
//       str[j + 1] = str[j];
//       j--;
//     }
//     str[j + 1] = key;
//   }
//   return str;
// }

unordered_map<char, int> get_hash_map(string str) {
  unordered_map<char, int> hash_map;
  for (auto c : str) {
    if (hash_map.find(c) == hash_map.end()) {
      hash_map[c] = 1;
    } else {
      hash_map[c]++;
    }
  }
  return hash_map;
}

int main() {
  string s = "a";
  string t = "ab";
  unordered_map<char, int> hash_map1 = get_hash_map(s);
  unordered_map<char, int> hash_map2 = get_hash_map(t);

  bool res = true;
  if(hash_map1.size() != hash_map2.size()){
    res = false;
  }
  for(auto it=hash_map1.begin(); it!= hash_map1.end();it++)
  {
    if(hash_map2.find(it->first) == hash_map2.end() || hash_map2[it->first] != it->second){
      res = false;
      break;
    }
  }

  cout << (res ? "True" : "False") << endl;
  return 0;
}