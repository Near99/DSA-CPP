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
     * @brief Solution of with return value keep updating root recursively.
     *
     * @param root Binary tree root pointer.
     * @return TreeNode* The new root pointer.
     */
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return root;
        TreeNode *temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;
        return root;
    }

    /**
     * @brief Solution that inverts tree nodes in place recursively.
     * I personally perfer this approach as it's easier to understand.
     *
     * @param root Binary tree root pointer.
     * @return void
     */
    void treeInvert(TreeNode *root) {
        if (!root) return;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        treeInvert(root->left);
        treeInvert(root->right);
    }
};