#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// from 48 - 57;
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
                if (str[i] == '-') {
                    t = "-";
                } else {
                    t = "";
                }
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
    // string str = "a56b6()_345!@$8";
    string str = "a56b-6-8()_56!@$-a";
    Solution s;
    vector<int> ans = s.GetTopThreeNum(str);
    for (auto i : ans) {
        std::cout << i << std::endl;
    }
    return 0;
}