#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const auto &str : strs){
            string key = str;
            sort(key.begin(),key.end());
            mp[key].emplace_back(str);
        }

        vector<vector<string>> ans;
        for (const auto &x : mp){
            ans.emplace_back(x.second);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
