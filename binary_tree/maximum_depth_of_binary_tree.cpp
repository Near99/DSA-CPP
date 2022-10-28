#include <algorithm>

class TreeNode {
   public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    /**
     * @brief So this is to calculate the height of the tree.
     *
     * @param root Binary tree root pointer.
     * @return int Height of the tree.
     */
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};