#include <vector>
#include <iostream>
#include <string>   // For string in printTreeStructureRecursive
#include <limits>   // For numeric_limits to get INT_MIN as sentinel
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int NULL_NODE_SENTINEL = numeric_limits<int>::min();
TreeNode* buildTreeRecursiveHelper(const vector<int>& nodes, int index) {
    if (index >= nodes.size()) {
        return nullptr;
    }
    if (nodes[index] == NULL_NODE_SENTINEL) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[index]);

    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;

    root->left = buildTreeRecursiveHelper(nodes, left_child_index);
    root->right = buildTreeRecursiveHelper(nodes, right_child_index);

    return root;
}

TreeNode* buildTreeFromList(const vector<int>& nodes) {
    if (nodes.empty()) {
        return nullptr;
    }
    return buildTreeRecursiveHelper(nodes, 0);
}

void deleteTreeRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTreeRecursive(root->left);
    deleteTreeRecursive(root->right);
    delete root;
}

void printTreeInOrderRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTreeInOrderRecursive(root->left);
    cout << root->val << " ";
    printTreeInOrderRecursive(root->right);
}

void printTreePreOrderRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printTreePreOrderRecursive(root->left);
    printTreePreOrderRecursive(root->right);
}

void printTreePostOrderRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTreePostOrderRecursive(root->left);
    printTreePostOrderRecursive(root->right);
    cout << root->val << " ";
}

void printTreeStructureRecursive(TreeNode* root, int current_indent = 0, int indent_step = 4) {
    if (root == nullptr) {
        return;
    }

    int next_level_indent = current_indent + indent_step;
    printTreeStructureRecursive(root->right, next_level_indent, indent_step);
    cout << string(current_indent, ' ') << root->val << endl;
    printTreeStructureRecursive(root->left, next_level_indent, indent_step);
}

int countNumNodesRecursive(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    return 1 + countNumNodesRecursive(root->left) + countNumNodesRecursive(root->right);
}


int main() {

    vector<int> nums = {1};

    TreeNode* root = buildTreeFromList(nums);

    cout << countNumNodesRecursive(root) << endl;

    return 0;
}
