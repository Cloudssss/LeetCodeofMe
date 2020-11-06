#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int get(int x){
        int res = 0;
        while (x){
            res += x%2;
            x/=2;
        }
        return res;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001,0);
        for (const auto x : arr){
            bit[x] = get(x);
        }

        sort(arr.begin(),arr.end(),[&bit](int x, int y){
            if (bit[x]< bit[y])
                return true;
            if (bit[x]>bit[y])
                return false;
            return x<y;
        });
        return arr;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
