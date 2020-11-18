#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n;) {
            int sumGas = 0, sumCost = 0;
            int cnt = 0;
            while (cnt < n){
                int j = (i + cnt)%n;
                sumGas += gas[j];
                sumCost += cost[j];

                if (sumCost > sumGas)
                    break;

                ++cnt;
            }

            if ( cnt == n)
                return i;

            i = i + cnt + 1;
        }

        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
