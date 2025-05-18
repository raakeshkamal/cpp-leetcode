#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

template <typename T> class Stack {
private:
  vector<T> items;

public:
  bool is_empty() { return items.empty(); }
  size_t size() { return items.size(); }
  T pop() {
    T last = T();
    if (!is_empty()) {
      last = items[items.size() - 1];
      items.pop_back();
    }
    return last;
  }
  void push(T new_item) { return items.push_back(new_item); }
};

int main() {

  return 0; }