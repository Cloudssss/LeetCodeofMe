#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> minfreq(26,INT32_MAX);
        vector<int> freq(26,0);

        for (const auto& word : A)
        {
            fill(freq.begin(),freq.end(),0);
            for (auto c : word)
            {
                freq[c-'a']++;
            }

            for (int i = 0; i < 26; ++i) {
                minfreq[i] = min(minfreq[i],freq[i]);
            }
        }

        vector<string> ans;

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minfreq[i]; ++j) {
                ans.emplace_back(1,i+'a');
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
