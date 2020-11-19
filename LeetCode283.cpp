#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(),left = 0, right = 0;
        while (right < n) {
            if (nums[right])
            {
                swap(nums[left], nums[right]);
                ++left;
            }
            ++right;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
