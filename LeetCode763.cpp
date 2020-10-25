#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        int last[26];

        for (int i = 0; i < n; ++i) {
            last[S[i]-'a'] = i;
        }

        vector<int> count;
        int start = 0, end = 0;

        for (int i = 0; i < n; ++i) {
            end = max(end,last[S[i]-'a']);
            if ( i == end)
            {
                count.push_back(end - start + 1);
                start = end;
            }
        }
        return count;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
