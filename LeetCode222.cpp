#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int level = 0;
        TreeNode* node = root;
        while (node != nullptr){
            ++level;
            node = node->left;
        }
        int low = 1 << (level -1), high = (1 << level) -1;

        while (low < high){
            int mid = (high - low + 1)/2 +low;
            if (exist(root,level ,mid)){
                low = mid;
            } else{
                high = mid -1;
            }
        }
        return low;
    }

    bool exist(TreeNode* node, int level, int k){
        int bits = 1 << (level - 2);
        while (bits > 0 ){
            if ( !(bits&k) )
                node = node->left;
            else
                node = node->right;
            bits >>= 1;
        }
        return node != nullptr;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
