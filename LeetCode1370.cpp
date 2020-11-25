#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        vector<int> num(26);
        for (auto &c : s){
            ++num[c-'a'];
        }

        string ans;
        while (ans.size() < s.size()){
            for (int i = 0; i < 26; ++i) {
                if (num[i]){
                    ans.push_back(i+'a');
                    --num[i];
                }
            }

            for (int i = 25; i >= 0; --i) {
                if (num[i]){
                    if (num[i]){
                        ans.push_back(i+'a');
                        --num[i];
                    }
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
