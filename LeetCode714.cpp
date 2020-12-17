#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int sell = 0, buy = -prices[0];
        for (int i = 1; i < n; ++i) {
            tie(sell,buy) = pair<int,int>(max(sell,buy + prices[i] -fee),max(buy, sell - prices[i]));
        }
        return sell;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
