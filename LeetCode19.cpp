#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        int length = 0;
        ListNode* flag = dummy;
        while (flag!= nullptr)
        {
            flag = flag->next;
            length++;
        }

        flag = dummy;
        for (int i = 0; i < length - n -1; ++i) {
            flag = flag->next;
        }
        flag->next = flag->next->next;
        return dummy->next;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
