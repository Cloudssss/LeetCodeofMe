#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums,int target, bool lower){
        int left = 0, right = nums.size()-1, ans = nums.size();

        while (left <= right){
            int mid = (left + right)/2;
            if (nums[mid] > target || (nums[mid] >= target && lower)){
                ans = mid;
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums,target,true);
        int right = binarySearch(nums,target, false) - 1;
        if (left <= right && right < nums.size() && nums[left] == target && nums[right] == target)
            return {left,right};
        return {-1,-1};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
