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
            } else if (i == str.size() - 1 && t.size() != 0) {
                std::cout << "called" << std::endl;
                result.push_back(stoi(t));
            } else {
                continue;
            }
        }
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
    // 56 6 345 8
    // a56b-6-8()_56!@$-a
    string str = "a56b6()_345!@$8";
    Solution s;
    vector<int> ans = s.GetTopThreeNum(str);
    for (auto i : ans) {
        std::cout << i << std::endl;
    }
    return 0;
}