#include <assert.h>

#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 1, max = 0;
        while (sell < prices.size()) {
            if (prices[sell] > prices[buy]) {
                int currMax = prices[sell] - prices[buy];
                max = currMax > max ? currMax : max;
            } else {
                buy = sell;
            }
            sell++;
        }
        return max;
    }
};

int main() {
    vector<int> input = {7, 1, 5, 3, 6, 4};
    int output = 5;
    Solution solution;
    assert(solution.maxProfit(input) == output);
}
