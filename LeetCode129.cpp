#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode* root,int presum)
    {
        if (root == nullptr)
            return 0;
        int sum = presum*10+root->val;
        if (root->left== nullptr && root->right== nullptr)
            return sum;
        return dfs(root->left,sum)+dfs(root->right,sum);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
