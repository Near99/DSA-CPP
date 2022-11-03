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
    for (int i = 97; i <= 122; i++) {
        assert(list.removeFront().value_ == (char)i);
    }
    for (int i = 97; i <= 122; i++) {
        list.insertBack((char)i);
    }
    list.reverse();
    for (int i = 97; i <= 122; i++) {
        assert(list.removeEnd().value_ == (char)i);
    }
    assert(list.empty() == true);
    assert(list.size() == 0);
    return 0;
}
