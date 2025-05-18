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
  T peek() {
    if (!is_empty()) {
      return items[items.size() - 1];
    }
    return T();
  }
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

void build_stack(Stack<char> &s, char c) {
  if (!s.is_empty()) {
    if ((s.peek() == 'A' && c == 'B') || (s.peek() == 'C' && c == 'D')) {
      s.pop();
    } else {
      s.push(c);
    }
  } else {
    s.push(c);
  }
}

string unwind_stack(Stack<char> &s) {
  string str = "";
  while (!s.is_empty()) {
    str += s.pop();
  }
  return str;
}

int main() {
  string str = "ABFCACDB";
  Stack<char> s1;
  for (auto c : str) {
    build_stack(s1, c);
  }
  cout << unwind_stack(s1) << endl;
  return 0;
}