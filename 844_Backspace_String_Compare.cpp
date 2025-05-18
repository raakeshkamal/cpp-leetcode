#include <cstddef>
#include <iostream>
#include <string>
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

void build_stack(Stack<char> &s, char c) {
  if (c == '#') {
    s.pop();
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
  string str1 = "#fo##f";
  string str2 = "y#f#o##f";
  Stack<char> s1, s2;
  for (auto c : str1) {
    build_stack(s1, c);
  }
  for (auto c : str2) {
    build_stack(s2, c);
  }
  string res1 = unwind_stack(s1);
  string res2 = unwind_stack(s2);
  cout << ((res1 == res2) ? "True" : "False") << endl;
  return 0;
}