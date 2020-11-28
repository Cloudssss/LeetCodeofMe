#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        return result(nums,0,nums.size()-1);
    }

    int result(vector<int>& nums, int left, int right){
        if (left == right)
            return 0;

        int mid = (left + right)/2;
        int ret = result(nums,left,mid) + result(nums,mid+1,right);

        int i = left;
        int j = mid + 1;

        while ( i <= mid ){
            while (j<=right && nums[i] > 2 * nums[j])
                ++j;
            ret += ( j - 1 - mid );
            ++i;
        }

        vector<int> sorted(right - left + 1);
        int p1 = left, p2 = mid+1;
        int p = 0;

        while (p1<=mid || p2 <= right){
            if (p1 > mid)
                sorted[p++] = nums[p2++];
            else if (p2 > right)
                sorted[p++] = nums[p1++];
            else{
                if (nums[p1] < nums[p2])
                    sorted[p++] = nums[p1++];
                else
                    sorted[p++] = nums[p2++];
            }
        }

        for (int k = left; k <= right; ++k) {
            nums[k] = sorted[k-left];
        }

        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
