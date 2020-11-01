#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordSet;
    int n;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(),wordDict.end());
        n = s.size();
        backtrack(s,0);
        return ans[0];
    }

    void backtrack(const string& s, int index)
    {
        if (!ans.count(index))
        {
            if (index == n) {
                ans[index] = {""};
                return;
            }
            ans[index] = {};
            for (int i = index + 1; i <= n; ++i) {
                string word = s.substr(index, i - index);
                if (wordSet.count(word))
                {
                    backtrack(s,i);
                    for (const string& m : ans[i])
                    {
                        ans[index].push_back(m.empty()? word: word + " " + m);
                    }
                }
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
