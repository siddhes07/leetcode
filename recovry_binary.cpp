#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if(root == NULL)
            return;

        inorder(root->left);

        if(prev != NULL && root->val < prev->val) {
            if(first == NULL)
                first = prev;

            second = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if(first != NULL && second != NULL) {
            swap(first->val, second->val);
        }
    }
};

void inorderPrint(TreeNode* root) {
    if(root == NULL)
        return;

    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {

    /*
            3
           / \
          1   4
             /
            2

        BST wrong aahe.
        2 and 3 swapped aahet.
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before Recovery (Inorder): ";
    inorderPrint(root);

    Solution obj;
    obj.recoverTree(root);

    cout << "\nAfter Recovery (Inorder): ";
    inorderPrint(root);

    cout << endl;

    return 0;
}