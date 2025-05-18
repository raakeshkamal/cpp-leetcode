#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int val;
  Node *next;

  Node(int num) {
    val = num;
    next = nullptr;
  }
};

class LinkedList {
private:
  Node *head;

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
      cout << node->val << " ";
      node = node->next;
    }
    cout << endl;
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
  }
  void push_front(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
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
  }
};

int main() {
  LinkedList list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_front(0);

  std::cout << "Linked list: ";
  list.print(); // Output: 0 -> 1 -> 2 -> 3 -> nullptr

  list.delete_node(2);
  std::cout << "Linked list after deleting 2: ";
  list.print(); // Output: 0 -> 1 -> 3 -> nullptr

  list.delete_node(0);
  std::cout << "Linked list after deleting 0: ";
  list.print(); // Output: 1 -> 3 -> nullptr
  list.delete_node(3);
  std::cout << "Linked list after deleting 3: ";
  list.print(); // Output: 1 -> nullptr cwd: /home/tall-roland

  list.delete_node(1);
  std::cout << "Linked list after deleting 1: ";
  list.print(); // Output: nullptr
  return 0;
}