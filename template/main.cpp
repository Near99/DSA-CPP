#include <assert.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> GetTopThreeNum(string str) {
        vector<int> result;
        string t = "";
        for (int i = 0; i < str.size(); i++) {
            if ((str[i] >= 48 && str[i] <= 57)) {
                t += str[i];
            } else if (str[i] == 45 && t.size() == 0) {
                t += str[i];
            } else if (t.size() > 0 && t != "-") {
                result.push_back(stoi(t));
                t = str[i] == '-' ? "-" : "";
            } else {
                continue;
            }
        }
        if (t.size() != 0 && t != "-") result.push_back(stoi(t));
        std::sort(result.begin(), result.end(), std::greater<int>());
        if (result.size() <= 3) return result;
        vector<int> ans;
        for (int i = 0; i < 3; i++) {
            ans.push_back(result[i]);
        }
        return ans;
    }
};

int main() {
    string input_str1 = "a56b6()_345!@$8";
    vector<int> res_1 = {345, 56, 8};
    string input_str2 = "a56b-6-8()_56!@$-a";
    vector<int> res_2 = {56, 56, -6};
    Solution s;
    vector<int> ans;
    ans = s.GetTopThreeNum(input_str1);
    for (int i = 0; i < res_1.size(); i++) {
        assert(ans[i] == res_1[i]);
    }
    ans = s.GetTopThreeNum(input_str2);
    for (int i = 0; i < res_2.size(); i++) {
        assert(ans[i] == res_2[i]);
    }
    return 0;
}
