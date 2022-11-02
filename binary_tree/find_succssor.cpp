class BinaryTree {
   public:
    int value;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;
    BinaryTree* parent = nullptr;

    BinaryTree(int value) { this->value = value; }
};

class Solution {
   public:
    BinaryTree* findSuccssor(BinaryTree* tree, BinaryTree* node) {
        if (node->right != nullptr) {
            return leftMost(node->right);
        }
        return rightMost(node);
    }

    BinaryTree* leftMost(BinaryTree* node) {
        auto* curr = node;
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    }

    BinaryTree* rightMost(BinaryTree* node) {
        auto* curr = node;
        while (curr->parent != nullptr && curr->parent->right == curr) {
            curr = curr->parent;
        }
        return curr->parent;
    }
};