#include <iostream>
#include <vector>

class Solution {
   public:
    /**
     * @brief Bitwise XOR(^) operation.
     *
     * @param nums Input array of integers with every element appears twice
     * except for one. e.g. [4, 1, 2, 1, 2]
     * This is an interesting problem to solve using the facts and tricks of bit
     * manipulation.
     * Two facts are: x^x=0, x^0s=x;
     * So the tricks are clear, the input array contains a bunch of duplicates
     * except for one element which means these elements XOR together is gonna
     * be 0 (first fact: x^x=0). After we went through these duplicates there's
     * only one unique number left, therefore we get to the answer (second fact:
     * x^0s=x).
     *
     * @return int Answer.
     */
    int singleNumber(std::vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            ans ^= n;
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {4, 1, 2, 1, 2};
    Solution solution;
    std::cout << solution.singleNumber(nums) << std::endl;
    return 0;
}