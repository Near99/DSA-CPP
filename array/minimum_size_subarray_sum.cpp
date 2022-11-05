#include <assert.h>

#include <vector>

using namespace std;

/**
 * @brief Classical sliding window question.
 */
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, ans = __INT_MAX__, sum = 0;
        while (right < nums.size()) {
            sum += nums[right++];
            while (sum >= target) {
                int length = right - left;
                ans = length < ans ? length : ans;
                sum -= nums[left++];
            }
        }
        return ans == __INT_MAX__ ? 0 : ans;
    }
};

int main() {
    vector<int> input = {2, 3, 1, 2, 4, 3};
    int ans = 2, target = 7;
    Solution solution;
    assert(solution.minSubArrayLen(target, input) == ans);
}