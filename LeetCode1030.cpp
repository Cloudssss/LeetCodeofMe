#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dis(int r, int c, int r0, int c0){
        return abs(r-r0)+abs(c-c0);
    }

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int n = max(R-1-r0,r0) + max(C-1-c0,c0);
        vector<vector<vector<int>>> ans(n + 1);

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                int m = dis(i,j,r0,c0);
                ans[m].push_back({i,j});
            }
        }

        vector<vector<int>> ret;
        for (auto& bucket : ans){
            for (auto& it : bucket){
                ret.push_back(it);
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
