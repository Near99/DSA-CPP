#include <assert.h>

#include <vector>

#include "bst.h"

using namespace bst;
using namespace std;

int main() {
    BinarySearchTree tree;
    vector<int> v = {10, 5, 15, 2, 3, 4, 9, 13, 22, 1, 14, 19};
    vector<int> p = {120, 105, 125, 12, 99, 131, 222, 1872, 140};
    assert(tree.isEmpty() == true);
    for (int n : v) {
        tree.insert(n);
    }
    cout << "Count: " << tree.count() << endl;
    cout << "Max: " << tree.getMax() << endl;
    cout << "Min: " << tree.getMin() << endl;
    cout << "Height: " << tree.getHeight() << endl;
    cout << "Valid? : " << tree.isValid() << endl;
    for (int n : v) {
        assert(tree.contain(n) == true);
    }
    for (int n : p) {
        assert(tree.contain(n) == false);
    }
    assert(tree.successor(4) == 5);
    assert(tree.successor(1) == 2);
    assert(tree.successor(14) == 15);
    assert(tree.successor(9) == 10);
    for (int n : v) {
        tree.remove(n);
        assert(tree.isValid() == true);
    }
    assert(tree.isEmpty() == true);
    assert(tree.isValid() == true);

    return 0;
}
