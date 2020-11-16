#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),[](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0] || (a[0]==b[0] && a[1] > b[1]);
        });
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const auto &person : people){
            int flag = 0;
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()){
                    ++flag;
                }
                if (flag == person[1]){
                    ans[i] = person;
                    break;
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
