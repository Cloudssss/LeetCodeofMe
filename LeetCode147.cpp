#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode *newhead = head, *flag = head->next, *lastofflag = head;
        while ( flag != nullptr ){
            ListNode* curr = newhead;
            if (flag->val < newhead->val){
                ListNode* fakeflag= flag;
                flag = flag->next;
                lastofflag->next = flag;
                fakeflag->next = newhead;
                newhead = fakeflag;
                continue;
            }

            if (flag->val >= lastofflag->val){
                flag = flag->next;
                lastofflag = lastofflag->next;
                continue;
            }

            while (!(flag->val >= curr->val && flag->val < curr->next->val) ){
                curr = curr->next;
            }

            ListNode* fakeflag = flag;
            flag = flag->next;
            lastofflag->next = flag;
            fakeflag->next = curr->next;
            curr->next = fakeflag;
        }

        return newhead;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
