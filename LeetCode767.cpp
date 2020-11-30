#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        if (S.size()<2)
            return S;
        vector<int> count(26);
        int maxCount = 0;
        int length = S.size();

        for (int i = 0; i < length; ++i) {
            ++count[S[i]-'a'];
        }

        for (int i = 0; i < 26; ++i) {
            maxCount = max(maxCount,count[i]);
        }

        if (maxCount > (length+1)/2)
            return "";

        auto cmp = [&](const char &letter1, const char &letter2){
            return count[letter1-'a'] < count[letter2 - 'a'];
        };

        priority_queue<char, vector<char>, decltype(cmp)> queue{cmp};

        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0)
                queue.push(i+'a');
        }

        string sb;
        while (queue.size() > 1){
            char letter1 = queue.top();queue.pop();
            char letter2 = queue.top();queue.pop();
            sb += letter1;
            sb += letter2;
            --count[letter1-'a'];
            --count[letter2-'a'];

            if (count[letter1-'a'] > 0)
                queue.push(letter1);
            if (count[letter2-'a']>0)
                queue.push(letter2);
        }

        if (queue.size()>0)
            sb += queue.top();
        return sb;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
