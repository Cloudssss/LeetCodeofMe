#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> compare;
        int n = arr2.size();
        for (int i = 0; i < n; ++i) {
            compare[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(), [&compare](int x, int y){
           if (compare.count(x)){
               if (compare.count(y))
                   return compare[x] < compare[y];
               else
                   return true;
           } else{
               if (compare.count(y))
                   return false;
               else
                   return x < y;
           }
        });

        return arr1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
