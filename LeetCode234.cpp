#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* frontpoint;
public:

    bool check(ListNode* currentpoint)
    {
        if (currentpoint == nullptr)
            return true;
        if (check(currentpoint->next) == false)
            return false;
        else if (currentpoint->val!=frontpoint->val)
            return false;
        frontpoint = frontpoint->next;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        frontpoint = head;
        return check(frontpoint);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
