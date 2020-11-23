#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size()==0)
            return 0;

        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });

        int arrow = points[0][1];
        int ans = 1;
        for (const auto& p : points){
            if (p[0] > arrow)
            {
                arrow = p[1];
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
