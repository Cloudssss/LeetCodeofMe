#include <iostream>
#include <algorithm>
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *odd = head, *even = head->next;
        ListNode *evenhead = head->next;
        while (even!= nullptr && even->next!= nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
