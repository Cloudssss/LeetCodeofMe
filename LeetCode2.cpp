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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1;
        int len2 = 1;

        ListNode* p = l1;
        ListNode* q = l2;

        while (p->next!=NULL)
        {
            ++len1;
            p = p->next;
        }

        while (q->next!=NULL)
        {
            ++len2;
            q = q -> next;
        }

        if ( len1 > len2)
        {
            for (int i = 0; i < len1-len2; ++i) {
                q->next = new ListNode(0);
                q=q->next;
            }
        } else{
            for (int i = 0; i < len2 - len1; ++i) {
                p->next = new ListNode(0);
                p=p->next;
            }
        }

        p=l1;
        q=l2;

        ListNode* l3 = new ListNode(0);

        int flag = 0;
        int n = 0;
        ListNode* m = l3;
        while (p!=NULL)
        {
            n = p->val + q->val + flag;
            if (n>=10)
            {
                n = n - 10;
                flag = 1;
            } else {
                flag = 0;
            }
            m->next = new ListNode(n);
            p = p->next;
            q = q->next;
            m = m->next;
        }

        if (flag>0)
        {
            m->next = new ListNode(1);
        }

        return l3->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
