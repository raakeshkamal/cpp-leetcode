#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void print2DVector(vector<vector<int>> &matrix) {
  for (auto i : matrix) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> matrix1 = {{1, 2}, {3, 4}, {5, 6}};
  print2DVector(matrix1);
  int rows = 2;
  int cols = 3;
  vector<vector<int>> matrix2(rows, vector<int>(cols, 0));
  int idx = 0;
  for (auto i : matrix1) {
    for (auto j : i) {
      matrix2[idx/cols][idx%cols] = j;
      idx++;
    }
  }
  print2DVector(matrix2);
  return 0;
}