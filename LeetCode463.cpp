#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    constexpr static int dx[4] = {0, 1, -1, 0};
    constexpr static int dy[4] = {1, 0, 0, -1};

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1){
                    int cnt = 0;
                    for (int k = 0; k < 4; ++k) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        if (tx<0||tx>=m||ty<0||ty>=n||(grid[tx][ty]==0)){
                            ++cnt;
                        }
                    }
                    ans += cnt;
                }
            }
        }

        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
