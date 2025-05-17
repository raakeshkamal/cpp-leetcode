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

// Sentinel value to represent null nodes in the input vector.
// IMPORTANT: If this sentinel value (INT_MIN) itself is a valid node value in your tree,
// this approach for list representation will have a conflict.
// A more robust list representation in such cases would use `vector<optional<int>>`
// or pass a specific value known not to be in the tree data.
const int NULL_NODE_SENTINEL = numeric_limits<int>::min();

// --- Tree Building (Recursive) ---

// Recursive helper function to build the tree from a level-order list.
// `index` is the current position in the `nodes` vector to process.
TreeNode* buildTreeRecursiveHelper(const vector<int>& nodes, int index) {
    // Base case 1: If index is out of bounds of the list, it means no node here.
    if (index >= nodes.size()) {
        return nullptr;
    }
    // Base case 2: If the value at the current index is the sentinel for null, no node here.
    if (nodes[index] == NULL_NODE_SENTINEL) {
        return nullptr;
    }

    // Create the current node with the value from the list.
    TreeNode* root = new TreeNode(nodes[index]);

    // Calculate indices for left and right children in the level-order list.
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;

    // Recursively build the left and right subtrees.
    root->left = buildTreeRecursiveHelper(nodes, left_child_index);
    root->right = buildTreeRecursiveHelper(nodes, right_child_index);

    return root;
}

// Main function to build the tree from a list representation.
// The list `nodes` is expected to be in level-order (heap-like structure).
TreeNode* buildTreeFromList(const vector<int>& nodes) {
    if (nodes.empty()) {
        return nullptr; // Handle empty list case: no tree.
    }
    // Start recursion from the root (index 0).
    // The helper handles the case where nodes[0] itself is NULL_NODE_SENTINEL.
    return buildTreeRecursiveHelper(nodes, 0);
}

// --- Tree Deletion (Recursive) ---

// Recursively deletes the tree using a post-order traversal.
// This ensures children are deleted before their parent.
void deleteTreeRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTreeRecursive(root->left);
    deleteTreeRecursive(root->right);
    delete root; // Delete the node itself after its children.
}

// --- Tree Printing (Recursive) ---

// Prints the tree using In-order traversal (Left - Node - Right).
void printTreeInOrderRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTreeInOrderRecursive(root->left);
    cout << root->val << " ";
    printTreeInOrderRecursive(root->right);
}

// Prints the tree using Pre-order traversal (Node - Left - Right).
void printTreePreOrderRecursive(TreeNode* root) {
    if (root == nullptr) {
        // Optional: print a marker for nulls to see structure if desired
        // cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTreePreOrderRecursive(root->left);
    printTreePreOrderRecursive(root->right);
}

// Prints the tree using Post-order traversal (Left - Right - Node).
void printTreePostOrderRecursive(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTreePostOrderRecursive(root->left);
    printTreePostOrderRecursive(root->right);
    cout << root->val << " ";
}

// Prints the tree structure visually (rotated 90 degrees counter-clockwise).
// The right subtree is printed above the root, and the left subtree below.
// `current_indent` is the number of spaces for the current node's indentation.
// `indent_step` is how many more spaces to add for each level deeper.
void printTreeStructureRecursive(TreeNode* root, int current_indent = 0, int indent_step = 4) {
    if (root == nullptr) {
        return; // Don't print anything for a null node.
    }

    int next_level_indent = current_indent + indent_step;

    // Process the right child first (it will appear visually at the top).
    printTreeStructureRecursive(root->right, next_level_indent, indent_step);

    // Print the current node: indent it, then print its value.
    cout << string(current_indent, ' ') << root->val << endl;

    // Process the left child (it will appear visually at the bottom).
    printTreeStructureRecursive(root->left, next_level_indent, indent_step);
}


// --- Main function for testing ---
int main() {
    cout << "Using INT_MIN (" << NULL_NODE_SENTINEL << ") as null marker for nodes in list representation." << endl << endl;

    // Example 1: List: [1, 2, 3, NULL_NODE_SENTINEL, 4, NULL_NODE_SENTINEL, 5]
    // Visual tree structure:
    //       1
    //      / \
    //     2   3
    //      \   \
    //       4   5
    vector<int> tree_list1 = {1, 2, 3, NULL_NODE_SENTINEL, 4, NULL_NODE_SENTINEL, 5};
    TreeNode* root1 = buildTreeFromList(tree_list1);

    cout << "Tree 1:" << endl;
    cout << "  In-Order traversal: ";   printTreeInOrderRecursive(root1);   cout << endl;
    cout << "  Pre-Order traversal: ";  printTreePreOrderRecursive(root1);  cout << endl;
    cout << "  Post-Order traversal: "; printTreePostOrderRecursive(root1); cout << endl;
    cout << "  Structure:" << endl;
    printTreeStructureRecursive(root1);
    cout << "----------------------------" << endl;
    deleteTreeRecursive(root1);
    root1 = nullptr; // Good practice to nullify pointer after deletion.

    // Example 2: List: [3, 9, 20, NULL_NODE_SENTINEL, NULL_NODE_SENTINEL, 15, 7]
    // Visual tree structure:
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    vector<int> tree_list2 = {3, 9, 20, NULL_NODE_SENTINEL, NULL_NODE_SENTINEL, 15, 7};
    TreeNode* root2 = buildTreeFromList(tree_list2);

    cout << "Tree 2:" << endl;
    cout << "  In-Order traversal: ";   printTreeInOrderRecursive(root2);   cout << endl;
    cout << "  Pre-Order traversal: ";  printTreePreOrderRecursive(root2);  cout << endl;
    cout << "  Post-Order traversal: "; printTreePostOrderRecursive(root2); cout << endl;
    cout << "  Structure:" << endl;
    printTreeStructureRecursive(root2);
    cout << "----------------------------" << endl;
    deleteTreeRecursive(root2);
    root2 = nullptr;

    // Example 3: Empty list
    vector<int> tree_list3 = {};
    TreeNode* root3 = buildTreeFromList(tree_list3);
    cout << "Tree 3 (from empty list):" << endl;
    cout << "  In-Order traversal: "; printTreeInOrderRecursive(root3); cout << (root3 == nullptr ? "(null tree)" : "") << endl;
    cout << "  Structure:" << endl;
    if (root3 == nullptr) cout << "  (null tree structure)" << endl; else printTreeStructureRecursive(root3);
    cout << "----------------------------" << endl;
    deleteTreeRecursive(root3); // Safe to call on nullptr
    root3 = nullptr;

    // Example 4: List with only a null marker for the root [NULL_NODE_SENTINEL]
    vector<int> tree_list4 = {NULL_NODE_SENTINEL};
    TreeNode* root4 = buildTreeFromList(tree_list4);
    cout << "Tree 4 (from list with null root):" << endl;
    cout << "  In-Order traversal: "; printTreeInOrderRecursive(root4); cout << (root4 == nullptr ? "(null tree)" : "") << endl;
    cout << "  Structure:" << endl;
    if (root4 == nullptr) cout << "  (null tree structure)" << endl; else printTreeStructureRecursive(root4);
    cout << "----------------------------" << endl;
    deleteTreeRecursive(root4);
    root4 = nullptr;
    
    // Example 5: Right-skewed tree. List: [1, NULL, 2, NULL, NULL, NULL, 3]
    // Visual tree structure:
    //       1
    //        \
    //         2
    //          \
    //           3
    // Level order representation:
    // Index 0: 1
    // Index 1 (L of 1): NULL
    // Index 2 (R of 1): 2
    // Index 3 (L of NULL): (skip)
    // Index 4 (R of NULL): (skip)
    // Index 5 (L of 2): NULL
    // Index 6 (R of 2): 3
    vector<int> tree_list5 = {1, NULL_NODE_SENTINEL, 2, 
                                   NULL_NODE_SENTINEL, NULL_NODE_SENTINEL, /* children of the first NULL_NODE_SENTINEL (index 1) */
                                   NULL_NODE_SENTINEL, 3 /* children of node 2 (index 2) */}; 
    TreeNode* root5 = buildTreeFromList(tree_list5);
    cout << "Tree 5 (Right Skewed):" << endl;
    cout << "  In-Order traversal: ";   printTreeInOrderRecursive(root5);   cout << endl;
    cout << "  Pre-Order traversal: ";  printTreePreOrderRecursive(root5);  cout << endl;
    cout << "  Post-Order traversal: "; printTreePostOrderRecursive(root5); cout << endl;
    cout << "  Structure:" << endl;
    printTreeStructureRecursive(root5);
    cout << "----------------------------" << endl;
    deleteTreeRecursive(root5);
    root5 = nullptr;

    // Example 6: Complete tree {1, 2, 3, 4, 5, 6, 7}
    // Visual tree structure:
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    vector<int> tree_list6 = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root6 = buildTreeFromList(tree_list6);
    cout << "Tree 6 (Complete):" << endl;
    cout << "  In-Order traversal: ";   printTreeInOrderRecursive(root6);   cout << endl;
    cout << "  Pre-Order traversal: ";  printTreePreOrderRecursive(root6);  cout << endl;
    cout << "  Post-Order traversal: "; printTreePostOrderRecursive(root6); cout << endl;
    cout << "  Structure:" << endl;
    printTreeStructureRecursive(root6);
    cout << "----------------------------" << endl;
    deleteTreeRecursive(root6);
    root6 = nullptr;

    return 0;
}
