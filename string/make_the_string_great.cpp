#include <assert.h>

#include <string>

using namespace std;

/**
 * @brief First try leetcode daily problem.
 * Stack is used to solve it, and I just got to know that string in cpp has
 * these great methods..
 *
 * Time: O(n), Space: O(n).
 *
 * Using two pointers can solve this problem in linear time and constant space
 * but I don't know how..
 */
class Solution {
   public:
    string makeGood(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (ans.empty()) {
                ans.push_back(s[i]);
            } else {
                int t = ans.back() - s[i];
                if (t == 32 || t == -32) {
                    ans.pop_back();
                } else {
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};

int main() {
    string input = "leEeetcode";
    string s_ans = "leetcode";
    Solution s;
    string ans = s.makeGood(input);
    assert(ans.size() == s_ans.size());
    for (int i = 0; i < s_ans.size(); i++) {
        assert(ans[i] = s_ans[i]);
    }
    return 0;
}