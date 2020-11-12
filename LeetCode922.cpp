#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ans(A.size());
        int n = A.size();
        int x = 0;
        for (auto &i : A){
            if (i%2 == 0){
                ans[x] = i;
                x+=2;
            }
        }
        x = 1;
        for (auto &i : A){
            if (i%2 == 1){
                ans[x] = i;
                x+=2;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
