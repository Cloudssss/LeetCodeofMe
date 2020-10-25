#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        if (n<2)
            return false;

        int sum = accumulate(nums.begin(),nums.end(),0);
        int maxNum = *max_element(nums.begin(),nums.end());

        if (sum%2 == 1)
            return false;

        int target = sum / 2;
        if (maxNum > target)
            return false;

        vector<int> dp(target + 1, 0);
        dp[0] = true;

        for (int i = 0; i != n; ++i) {
            int num = nums[i];
            for (int j = target; j >=num ; --j) {
                dp[j] = dp[j] | dp[num];
            }
        }
        return dp[target];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
