#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size();
        for (int i = 0; i < n-1; ++i) {
            int m = prices[i+1] - prices[i];
            if (m > 0)
                ans += m;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
