#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for (auto &digit : num){
            while (stk.size()!=0 && k!=0 && stk.back() > digit){
                stk.pop_back();
                --k;
            }
            stk.push_back(digit);
        }

        while (k!=0){
            stk.pop_back();
            --k;
        }

        string ans = "";
        bool isLeadingZero = true;
        for (auto &digit : stk){
            if (isLeadingZero && digit == '0'){
                continue;
            }
            isLeadingZero = false;
            ans += digit;
        }

        return (ans == "") ? "0" : ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
