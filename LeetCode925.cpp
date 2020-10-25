#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        int n = typed.size();
        int m = name.size();
        for (j=0;j<n;++j)
        {
            if ( i < m && name[i] == typed[j])
            {
                ++i;
            } else if ( j > 0 && typed[j-1]==typed[j]){

            } else {
                return false;
            }
        }
        return i == m;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
