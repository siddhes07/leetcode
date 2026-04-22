#include <iostream>
#include <queue>
using namespace std;

// Tree Node structure
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

// Function to find minimum depth
int minDepth(TreeNode* root) {
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // If left subtree is NULL
    if (root->left == NULL)
        return minDepth(root->right) + 1;

    // If right subtree is NULL
    if (root->right == NULL)
        return minDepth(root->left) + 1;

    // If both children exist
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

// Function to create tree (level order)
TreeNode* buildTree() {
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;

    if (val == -1)
        return NULL;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->val << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            temp->left = new TreeNode(val);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->val << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            temp->right = new TreeNode(val);
            q.push(temp->right);
        }
    }

    return root;
}

// Main function
int main() {
    cout << "Build Binary Tree\n";

    TreeNode* root = buildTree();

    int result = minDepth(root);

    cout << "Minimum Depth of Binary Tree = " << result << endl;

    return 0;
}