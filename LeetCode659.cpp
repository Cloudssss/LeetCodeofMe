#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;

        for (const auto &item : nums) {
            ++countMap[item];
        }

        for (const auto &item : nums) {
            if (countMap[item] > 0){
                if (endMap[item-1] > 0){
                    --countMap[item];
                    --endMap[item-1];
                    ++endMap[item];
                } else{
                    if (countMap[item+1] > 0 && countMap[item+2]>0){
                        --countMap[item];
                        --countMap[item+1];
                        --countMap[item+2];
                        ++endMap[item+2];
                    } else
                        return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,4,5};
    Solution x;
    bool m = x.isPossible(nums);
    cout << m;
    return 0;
}
