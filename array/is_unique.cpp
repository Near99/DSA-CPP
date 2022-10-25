#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Bitwise approach.
 * Assume string contains lowercase characters from a-z;
 */
class is_unique {
public:
    bool check(string str)
    {
        if (str.size() > 26) {
            return false;
        }
        int checker = 0;
        for (int i = 0; i < str.size(); i++) {
            int index = str[i] - 'a';
            if ((checker & (1 << index)) > 0) {
                return false;
            }
            checker |= (1 << index);
        }
        return true;
    }
};

int main()
{
    is_unique unique_string;
    assert((unique_string.check("helloworld")) == false);
    assert((unique_string.check("nodup")) == true);
    return 0;
}