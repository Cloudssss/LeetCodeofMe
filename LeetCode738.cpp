#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        int n = strN.length();
        int i = 1;
        while (i<n && strN[i-1] <= strN[i])
        {
            ++i;
        }

        if (i<n){
            while (i>0 && strN[i-1]>strN[i]){
                --strN[i-1];
                --i;
            }
            for (++i;i<n;++i){
                strN[i] = '9';
            }
        }
        return stoi(strN);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
