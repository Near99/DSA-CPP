#include <assert.h>

#include <string>

#include "linked_list.h"

using namespace ll;

int main() {
    LinkedList<char> list;
    assert(list.empty() == true);
    assert(list.size() == 0);
    for (int i = 97; i <= 122; i++) {
        list.insertFront((char)i);
    }
    list.reverse();
    list.print();
    assert(list.empty() == false);
    assert(list.size() == 26);
    return 0;
}
