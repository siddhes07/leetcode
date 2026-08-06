#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int dfs(TreeNode* root, int current) {
        if (root == nullptr)
            return 0;

        current = (current << 1) | root->val;

        if (root->left == nullptr && root->right == nullptr)
            return current;

        return dfs(root->left, current) + dfs(root->right, current);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};

int main() {
    /*
            1
          /   \
         0     1
        / \   / \
       0  1  0  1

    Binary Numbers:
    100 = 4
    101 = 5
    110 = 6
    111 = 7

    Sum = 22
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    Solution sol;
    cout << "Sum of Root to Leaf Binary Numbers: "
         << sol.sumRootToLeaf(root) << endl;

    // Free memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}