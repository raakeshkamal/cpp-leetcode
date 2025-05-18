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
  string str = "abcdefd";
  char ch = 'e';
  Stack<char> s1;
  int i;
  for (i = 0; i < str.length(); i++) {
    s1.push(str[i]);
    if (str[i] == ch) {
      break;
    }
  }
  string rev_str = "";
  if (i == str.length()) {
    i = 0;
  } else {
    while (!s1.is_empty()) {
      rev_str += s1.pop();
    }
    i++;
  }
  for (; i < str.length(); i++) {
    rev_str += str[i];
  }
  cout << rev_str << endl;
  return 0;
}