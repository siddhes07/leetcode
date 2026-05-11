#include <iostream>
#include <queue>
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

class Solution {
public:
    int minDepth(TreeNode* root) {

        if (root == NULL)
            return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {

            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();

            // If leaf node found
            if (node->left == NULL && node->right == NULL)
                return depth;

            if (node->left)
                q.push({node->left, depth + 1});

            if (node->right)
                q.push({node->right, depth + 1});
        }

        return 0;
    }
};

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << "Minimum Depth = 0";
        return 0;
    }

    cout << "\nEnter tree nodes in level order (-1 for NULL):\n";

    int val;
    cin >> val;

    TreeNode* root = new TreeNode(val);

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << current->val << ": ";
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->val << ": ";
        cin >> rightVal;

        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    Solution obj;

    cout << "\nMinimum Depth = "
         << obj.minDepth(root);

    return 0;
}