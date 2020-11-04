#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0], right = newInterval[1];
        bool flag = false;

        vector<vector<int>> ans;
        for (const vector<int>& interval : intervals) {
            if (left > interval[1])
                ans.push_back(interval);
            else if (right < interval[0]){
                if (!flag){
                    ans.push_back({left,right});
                    flag = true;
                }
                ans.push_back(interval);
            } else{
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }

        if (!flag)
        {
            ans.push_back({left,right});
        }

        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
