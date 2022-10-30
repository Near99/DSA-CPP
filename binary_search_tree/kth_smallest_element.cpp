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
    Solution() : counter_(0), ans_(0) {}
    int kthSmallest(TreeNode *root, int k) {
        helper(root, k);
        return ans_;
    }

   private:
    int counter_;
    int ans_;
    void helper(TreeNode *root, int k) {
        if (root == nullptr || counter_ >= k) return;
        helper(root->left, k);
        counter_++;
        if (counter_ == k) {
            ans_ = root->val;
            return;
        }
        helper(root->right, k);
    }
};
