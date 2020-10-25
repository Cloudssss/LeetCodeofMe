#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        vector<vector<int> > res;
        if (nums.size()<4)
        {
            return res;
        }

        int a,b,c,d,_size=nums.size();
        for (int a = 0; a <= _size - 4; ++a)
        {
            if (a>0&&nums[a-1]==nums[a]) continue;
            for (int b = a+1; b <= _size-3 ; ++b)
            {
                if (b>a+1&&nums[b-1]==nums[b]) continue;
                c = b+1;
                d = _size-1;
                while (c<d)
                {
                    if (nums[a]+nums[b]+nums[c]+nums[d]<target)
                        c++;
                    else if (nums[a]+nums[b]+nums[c]+nums[d]>target)
                        d--;
                    else
                    {
                        res.push_back({nums[a],nums[b],nums[c],nums[d]});
                        while (c<d&&nums[c]==nums[c+1])
                        {
                            c++;
                        }
                        while (c<d&&nums[d]==nums[d-1])
                        {
                            d--;
                        }
                        c++;
                        d--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
