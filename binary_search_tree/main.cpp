#include <vector>

#include "bst.h"

using namespace bst;
using namespace std;

int main() {
    BinarySearchTree tree;
    vector<int> v = {10, 5, 15, 2, 9, 13, 22, 1, 14};
    for (int n : v) {
        tree.insert(n);
    }
    cout << "Count: " << tree.count() << endl;
    cout << "Max: " << tree.getMax() << endl;
    cout << "Min: " << tree.getMin() << endl;
    cout << "Height: " << tree.getHeight() << endl;
    cout << "Valid? : " << tree.isValid() << endl;
    return 0;
}
