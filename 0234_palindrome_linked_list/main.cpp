#include "stdio.h"

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    /*
    * In order for it to be pallindrome the fist item needs to be same as the last item
    * Second item needs to be same as the second from last
    *
    */
    bool isPalindrome(ListNode* head)
    {
        int nContent = getN(head);

        // if nContent is even like 4 we check for i=0,1 OK, if odd like 5 we check for i=0,1 OK
        for (int i = 0; i < (nContent / 2); i++)
        {
            // compare the head+i th item with the head+nContent-1-i th item
            if (getValue(head, i) != getValue(head, nContent - 1 - i))
            {
                return 0;
            }
        }

        return 1;
    }

    int getN(ListNode* head)        // Gathers the number of content in the linked list
    {
        int nContent = 1; // head is the first content

        while (head->next != nullptr)
        {
            head = head->next;
            nContent++;
        }

        return nContent;
    }

    int getValue(ListNode* head, int n)      // Gathers the nth value from the list, 0th pos is the head
    {
        for (int i = 0; i < n; i++)
        {
            // check for the nullptr too
            if (head->next == nullptr)
            {
                return -1; // Error
            }

            head = head->next;
        }

        return head->val;
    }
};

int main(void)
{
    Solution solution;

    /*
    ListNode node4 = ListNode(10);
    ListNode node3 = ListNode(5, &node4);
    ListNode node2 = ListNode(0, &node3);
    ListNode node1 = ListNode(5, &node2);
    ListNode node0 = ListNode(10, &node1); // head
    */

    ListNode node3 = ListNode(10);
    ListNode node2 = ListNode(5, &node3);
    ListNode node1 = ListNode(5, &node2);
    ListNode node0 = ListNode(10, &node1); // head

    printf("Address of head node is : %p\n", &node0);
    solution.isPalindrome(&node1);
    printf("Address of head node is : %p\n", &node0); // The solution method does not change the adr
    printf("Value of head.next.next is expected 0 and it is %d\n", node0.next->next->val);
    printf("Is the example pallindrome?\nAnswer is : %d\n", solution.isPalindrome(&node0));
    return 0;
}