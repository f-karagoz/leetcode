#include "stdio.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        int nContent = 0;

        while (head->next != nullptr)
        {
            head = head->next;
            nContent++;
        }

        return 0; // TODO temp return
    }
};

int main(void)
{
    Solution solution;

    ListNode node4 = ListNode(10);
    ListNode node3 = ListNode(5, &node4);
    ListNode node2 = ListNode(0, &node3);
    ListNode node1 = ListNode(5, &node2);
    ListNode node0 = ListNode(10, &node1); // head

    printf("Address of head node is : %p\n", &node0);
    solution.isPalindrome(&node1);
    printf("Address of head node is : %p\n", &node0); // The solution method does not change the adr
    printf("Value of head.next.next is expected 0 and it is %d\n", node0.next->next->val);
    return 0;
}