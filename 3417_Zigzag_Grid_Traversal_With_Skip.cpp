#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void print1DVector(vector<int> arr) {
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

void print2DVector(vector<vector<int>> &matrix) {
  for (auto i : matrix) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  print2DVector(mat);
  vector<int> res;
  int ctr = 0;
  for (int i = 0; i < mat.size(); i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < mat[0].size(); j++) {
        if (ctr++ % 2 == 0) {
          res.push_back(mat[i][j]);
        }
      }
    } else {
      for (int j = mat[0].size() - 1; j >= 0; j--) {
        if (ctr++ % 2 == 0) {
          res.push_back(mat[i][j]);
        }
      }
    }
  }
  print1DVector(res);
  return 0;
}