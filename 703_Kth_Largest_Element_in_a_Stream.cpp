#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

class KthLargest {
private:
  vector<int> results;
  int elem;
  void insert_sort() {
    for (int i = 1; i < results.size(); i++) {
      int key = results[i];
      int j = i - 1;
      while (j >= 0 && results[j] <= key) {
        results[j + 1] = results[j];
        j--;
      }
      results[j + 1] = key;
    }
  }

public:
  KthLargest(int k, vector<int> &nums) {
    elem = k;
    results = nums;
    insert_sort();
  }

  int add(int val) {
    results.push_back(val);
    insert_sort();
    return results[elem - 1];
  }
};

void print_1d_vector(vector<int> &arr) {
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums = {7, 7, 7, 7, 8, 3};
  KthLargest obj = KthLargest(4, nums);
  cout << obj.add(2) << endl;
  cout << obj.add(10) << endl;
  cout << obj.add(9) << endl;
  cout << obj.add(9) << endl;
  // cout << obj.add(4) << endl;
}
