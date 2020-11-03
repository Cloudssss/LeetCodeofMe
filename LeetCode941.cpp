#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        int i = 0;

        while (i < n-1 && A[i] < A[i+1])
            i++;

        if (i == 0 || i == n-1)
            return false;

        while (i < n-1 && A[i] > A[i+1])
            i++;

        if (i != n-1)
            return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
