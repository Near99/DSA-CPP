#include <iostream>

using namespace std;

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

class BinarySearchTree {
   public:
    explicit BinarySearchTree() : _root(nullptr) {}

    void insert(int value) { _insert(&_root, value); }

    void traverse() { _traverse(_root); }

    void print() { cout << _root->value << endl; }

   private:
    struct Node* _root;

    void _insert(struct Node** root, int value) {
        if ((*root) == nullptr) {
            struct Node* new_node = new struct Node;
            new_node->value = value;
            new_node->left = nullptr;
            new_node->right = nullptr;
            *root = new_node;
        } else if (value < (*root)->value) {
            _insert(&(*root)->left, value);
        } else {
            _insert(&(*root)->right, value);
        }
    }

    void _traverse(struct Node* root) {
        if (root == nullptr) return;
        _traverse(root->left);
        cout << root->value << endl;
        _traverse(root->right);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(20);
    bst.insert(100);
    bst.insert(24);
    bst.insert(15);
    bst.insert(30);
    bst.traverse();
    return 0;
}
