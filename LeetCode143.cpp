#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head== nullptr)
            return;

        vector<ListNode*> vec;
        ListNode* flag = head;
        while (flag!= nullptr)
        {
            vec.push_back(flag);
            flag=flag->next;
        }
        int n = vec.size();
        int i = 0;
        int j = n-1;
        while ( i < j)
        {
            vec[i]->next = vec[j];
            ++i;
            if (i == j)
                break;
            vec[j]->next = vec[i];
            --j;
        }
        vec[i]->next = nullptr;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
