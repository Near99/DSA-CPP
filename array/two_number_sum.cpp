#include <assert.h>

#include <unordered_set>
#include <vector>

using namespace std;

vector<int> two_number_sum(vector<int> array, int target) {
    unordered_set<int> set;
    for (int num : array) {
        int i = target - num;
        if (set.find(i) != set.end()) {
            return vector<int>{i, num};
        }
        set.insert(num);
    }
    return {};
}

int main() {
    vector<int> input = {3, 5, -4, 8, 11, 1, -1, 6};
    vector<int> aws = {11, -1};
    vector<int> res = two_number_sum(input, 10);
    for (int i = 0; i < res.size(); i++) {
        assert(res[i] == aws[i]);
    }
}