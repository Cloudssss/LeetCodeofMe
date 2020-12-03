#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> primer(n,1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (primer[i]) {
                ++ans;
                for (int j = i*i; j < n; j+=i) {
                    primer[j] = 0;
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
