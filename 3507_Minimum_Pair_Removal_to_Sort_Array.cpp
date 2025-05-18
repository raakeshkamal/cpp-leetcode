#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int val;
  int pair_val;
  Node *next;

  Node(int num) {
    val = num;
    pair_val = INT32_MIN;
    next = nullptr;
  }
};

class LinkedList {
private:
  Node *head;
  void redo_pair_val() {
    Node *node = head;
    if (node != nullptr) {
      while (node->next != nullptr) {
        node->pair_val = node->val + node->next->val;
        node = node->next;
      }
      node->pair_val = INT32_MIN;
    }
  }

public:
  LinkedList() { head = nullptr; }
  ~LinkedList() {
    Node *node = head;
    if (node != nullptr) {
      while (node->next != nullptr) {
        Node *temp = node;
        node = node->next;
        delete temp;
      }
      delete node;
    }
  }
  void print() {
    Node *node = head;
    while (node != nullptr) {
      cout << node->val << ":" << node->pair_val << " ";
      node = node->next;
    }
    cout << endl;
  }
  bool is_non_decreasing() {
    Node *node = head;
    while (node != nullptr && node->next != nullptr) {
      if (node->next->val < node->val) {
        return false;
      }
      node = node->next;
    }
    return true;
  }
  void push_back(int val) {
    Node *newNode = new Node(val);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node *node = head;
    while (node->next != nullptr) {
      node = node->next;
    }
    node->next = newNode;
    redo_pair_val();
  }
  void push_front(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    redo_pair_val();
  }
  int replace_min_pair_val() {
    int min = INT32_MAX;
    Node *node = head;
    while (node != nullptr) {
      if (node->pair_val < min && node->pair_val != INT32_MIN) {
        min = node->pair_val;
      }
      node = node->next;
    }
    node = head;
    while (node != nullptr && node->pair_val != min) {
      node = node->next;
    }
    if (node != nullptr) {
      node->val = node->pair_val;
      Node* temp = node->next;
      if (temp != nullptr) {
        node->next = temp->next;
        delete temp;
      }
    }
    redo_pair_val();
    return min;
  }
  void delete_node(int num) {
    Node *node = head;
    Node *prev = nullptr;
    while (node != nullptr && node->val != num) {
      prev = node;
      node = node->next;
    }
    if (node != nullptr) {
      if (prev == nullptr) { // node == head
        head = head->next;
        delete node;
      } else {
        prev->next = node->next;
        delete node;
      }
    }
    redo_pair_val();
  }
};

void print_bool(bool val) { cout << (val ? "True" : "False") << endl; }

int main() {
  LinkedList list;

  // list.push_back(5);
  // list.push_back(1);
  // list.push_back(2);
  // list.push_back(3);
  // list.push_front(0);

  // std::cout << "Linked list: " << endl;
  // list.print(); // Output: 0 -> 1 -> 2 -> 3 -> nullptr
  // print_bool(list.is_non_decreasing());

  // // list.delete_node(2);
  // std::cout << "Linked list after deleting: " << endl;
  // cout << list.replace_min_pair_val() << endl;
  // list.print(); // Output: 0 -> 1 -> 3 -> nullptr
  // print_bool(list.is_non_decreasing());

  // // list.delete_node(0);
  // cout << list.replace_min_pair_val() << endl;
  // std::cout << "Linked list after deleting: " << endl;
  // list.print(); // Output: 1 -> 3 -> nullptr
  // print_bool(list.is_non_decreasing());

  // // list.delete_node(3);
  // cout << list.replace_min_pair_val() << endl;
  // std::cout << "Linked list after deleting: " << endl;
  // list.print(); // Output: 1 -> nullptr cwd: /home/tall-roland
  // print_bool(list.is_non_decreasing());

  // // list.delete_node(1);
  // cout << list.replace_min_pair_val() << endl;
  // std::cout << "Linked list after deleting: " << endl;
  // list.print(); // Output: nullptr
  // print_bool(list.is_non_decreasing());

  vector<int> nums = {1,2,2};
  for (auto i : nums) {
    list.push_back(i);
  }

  int i = 0;

  while (!list.is_non_decreasing()) {
    i++;
    list.print();
    list.replace_min_pair_val();
  }
  list.print();
  cout << i << endl;
  return 0;
}