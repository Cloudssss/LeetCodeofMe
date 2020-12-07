#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int ret = m * (1 << (n-1));

        for (int i = 1; i < n; ++i) {
            int nOnes = 0;
            for (int j = 0; j < m; ++j) {
                if (A[j][0] == 1)
                    nOnes += A[j][i];
                else
                    nOnes += (1-A[j][i]);
            }
            int k = max(nOnes,m-nOnes);
            ret += k * (1<<(n-i-1));
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
