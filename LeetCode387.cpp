#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> frequency;
        for (auto ch : s)
        {
            ++frequency[ch];
        }
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (frequency[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
