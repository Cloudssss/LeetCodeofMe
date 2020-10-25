#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();

        vector<int> left(n,0);
        for (int i = 1; i < n; ++i) {
            left[i] = (A[i-1]<A[i]? left[i - 1]+ 1:0);
        }

        vector<int> right(n,0);
        for (int i = n-2; i >=0 ; --i) {
            right[i] = (A[i]>A[i+1]?right[i+1] + 1:0);
        }

        int m = 0;
        for (int i = 1; i < n-1; ++i) {
            if (left[i]>0&&right[i]>0)
            {
                m = max(m,left[i]+right[i]+1);
            }
        }
        return m;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
