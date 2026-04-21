#include <iostream>
using namespace std;

// Definition of Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Function to check mirror condition
bool isMirror(TreeNode* left, TreeNode* right) {

    if (left == NULL && right == NULL)
        return true;

    if (left == NULL || right == NULL)
        return false;

    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Function to check symmetric tree
bool isSymmetric(TreeNode* root) {

    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}

// Function to create tree using preorder input
TreeNode* createTree() {

    int val;
    cout << "Enter value (-1 for NULL): ";
    cin >> val;

    if (val == -1)
        return NULL;

    TreeNode* root = new TreeNode(val);

    cout << "Enter left child of " << val << endl;
    root->left = createTree();

    cout << "Enter right child of " << val << endl;
    root->right = createTree();

    return root;
}

// Main function
int main() {

    cout << "Create Binary Tree\n";

    TreeNode* root = createTree();

    if (isSymmetric(root))
        cout << "Tree is Symmetric\n";
    else
        cout << "Tree is NOT Symmetric\n";

    return 0;
}