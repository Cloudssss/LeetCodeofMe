#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (const auto &c : tasks) {
            ++freq[c];
        }

        int maxExec = max_element(freq.begin(),freq.end(),[](const auto &a, const auto &b){
            return a.second < b.second;
        })->second;

        int maxCount = accumulate(freq.begin(),freq.end(),0,[=](int acc, const auto &u){
            return acc + (u.second == maxExec);
        });

        return max((maxExec-1)*(n+1)+maxCount,static_cast<int>(tasks.size()));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
