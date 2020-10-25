#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return build(S)==build(T);
    }

    string build(string str)
    {
        string ret;
        for (auto ch : str)
        {
            if (ch != '#')
                ret.push_back(ch);
            else if (!ret.empty())
                ret.pop_back();
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
