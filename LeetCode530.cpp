#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int &ans, int &pre)
    {
        if (root == nullptr)
            return;
        dfs(root->left,ans,pre);
        if (pre == -1)
            pre = root->val;
        else{
            ans = min(ans,root->val-pre);
            pre = root->val;
        }
        dfs(root->right,ans,pre);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT32_MAX;
        int pre = -1;
        dfs(root,ans,pre);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
