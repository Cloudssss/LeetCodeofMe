#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr = 0;
        int _size = nums.size();
        for (int i = 0; i < _size; ++i)
        {
            if (nums[i] == 0)
            {
                swap(nums[ptr],nums[i]);
                ptr++;
            }
        }

        for (int i = ptr; i < _size; ++i)
        {
            if (nums[i] == 1)
            {
                swap(nums[ptr],nums[i]);
                ptr++;
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
