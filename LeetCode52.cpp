#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> columns, diagonals1, diagonals2;
        return solve(n,0,columns,diagonals1,diagonals2);
    }

    int solve(int n,int row,unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2)
    {
        if (row == n)
        {
            return 1;
        }else{
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (columns.find(i) != columns.end())
                    continue;
                else if (diagonals1.find(row - i) != diagonals1.end())
                    continue;
                else if (diagonals2.find(row + i) != diagonals2.end())
                    continue;
                columns.insert(i);
                diagonals1.insert(row-i);
                diagonals2.insert(row+i);
                count += solve(n,row +1,columns,diagonals1,diagonals2);
                columns.erase(i);
                diagonals1.erase(row - i);
                diagonals2.erase(row + i);
            }
            return count;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
