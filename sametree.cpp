#include <iostream>
using namespace std;

// Binary Tree Node
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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // If both are NULL
        if (p == NULL && q == NULL)
            return true;

        // If one is NULL
        if (p == NULL || q == NULL)
            return false;

        // Check value and subtrees
        if (p->val == q->val)
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);

        return false;
    }
};

int main() {

    // Tree 1
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    if (obj.isSameTree(p, q))
        cout << "Trees are same" << endl;
    else
        cout << "Trees are not same" << endl;

    return 0;
}