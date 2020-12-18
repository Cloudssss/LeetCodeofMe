#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int as = 0, at = 0;
        for (char ch : s){
            as += ch;
        }
        for (char ch : t){
            at += ch;
        }
        return at -as;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
