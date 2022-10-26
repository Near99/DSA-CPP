#include <iostream>

#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

namespace bst {
class Node {
   public:
    explicit Node(int val) : value(val), left(nullptr), right(nullptr) {}
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree {
   public:
    explicit BinarySearchTree() : _root(nullptr) {}

    void insert(int value) { _insert(&_root, value); }

    void traverse() { _traverse(_root); }

    void print() { std::cout << _root->value << std::endl; }

    int count() { return _count(_root); }

    int getMax() { return _max(_root); }

    int getMin() { return _min(_root); }

    int getHeight() { return _height(_root); }

    bool isValid() { return _valid(_root, INT_MIN, INT_MAX); }

   private:
    Node* _root;

    void _insert(Node** root, int value) {
        if ((*root) == nullptr) {
            Node* new_node = new Node(value);
            new_node->value = value;
            *root = new_node;
        } else if (value < (*root)->value) {
            _insert(&(*root)->left, value);
        } else {
            _insert(&(*root)->right, value);
        }
    }

    void _traverse(Node* root) {
        if (root == nullptr) return;
        _traverse(root->left);
        std::cout << root->value << std::endl;
        _traverse(root->right);
    }

    int _count(Node* root) {
        if (root == nullptr) return 0;
        return 1 + _count(root->left) + _count(root->right);
    }

    int _min(Node* root) {
        if (root->left == nullptr) return root->value;
        return _min(root->left);
    }

    int _max(Node* root) {
        if (root->right == nullptr) return root->value;
        return _max(root->right);
    }

    int _height(Node* root) {
        if (root == nullptr) return 0;
        return 1 + MAX(_height(root->left), _height(root->right));
    }

    bool _valid(Node* root, int min, int max) {
        if (root == nullptr) return true;
        if (root->value <= min || root->value >= max) return false;
        return _valid(root->left, min, root->value) &&
               _valid(root->right, root->value, max);
    }
};
}  // namespace bst
#endif
