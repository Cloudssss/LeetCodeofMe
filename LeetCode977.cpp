#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size());
        int i = 0;
        int j = A.size() - 1;
        int flag = j;

        while (i!=j)
        {
            if (A[i]*A[i] > A[j] * A[j])
            {
                ans[flag] = A[i] * A[i];
                i++;
            }else {
                ans[flag] = A[j] * A[j];
                j--;
            }
            --flag;
        }
        ans[flag] = A[j]*A[j];

        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
