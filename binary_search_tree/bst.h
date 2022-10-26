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

    void remove(int value) { _remove(&_root, value, nullptr); }

    void traverse() { _traverse(_root); }

    void print() { _print(_root, nullptr); }

    int count() { return _count(_root); }

    int getMax() { return _max(_root); }

    int getMin() { return _min(_root); }

    int getHeight() { return _height(_root); }

    bool isValid() { return _valid(_root, INT_MIN, INT_MAX); }

    bool contain(int value) { return _contain(_root, value); }

    bool isEmpty() { return _empty(_root); }

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

    void _remove(Node** root, int target, Node* parent) {
        if ((*root) == nullptr) return;
        Node* d = (*root);
        if ((*root)->value == target) {
            if ((*root)->left == nullptr && (*root)->right == nullptr) {
                (*root) = nullptr;
            } else if ((*root)->left == nullptr || (*root)->right == nullptr) {
                if ((*root)->left == nullptr)
                    (*root) = (*root)->right;
                else
                    (*root) = (*root)->left;
            } else if ((*root)->left != nullptr && (*root)->right != nullptr) {
                (*root) = (*root)->left;
                if ((*root)->right == nullptr) {
                    (*root)->right = d->right;
                } else {
                    Node* r = (*root)->right;
                    while (r->right != nullptr) {
                        r = r->right;
                    }
                    r->right = d->right;
                }
            }
            delete d;
        } else if ((*root)->value > target) {
            _remove(&(*root)->left, target, *root);
        } else {
            _remove(&(*root)->right, target, *root);
        }
    }

    void _print(Node* root, Node* parent) {
        if (root == nullptr) return;
        if (parent == nullptr) {
            std::cout << "root node, no parent: " << root->value << std::endl;
        } else {
            std::cout << "Node's value: " << root->value
                      << " parent: " << parent->value << std::endl;
        }
        _print(root->left, root);
        _print(root->right, root);
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

    bool _contain(Node* root, int value) {
        if (root == nullptr) return false;
        if (value < root->value)
            return _contain(root->left, value);
        else if (value > root->value)
            return _contain(root->right, value);
        else
            return true;
    }

    bool _empty(Node* root) { return root == nullptr; }
};
}  // namespace bst
#endif
