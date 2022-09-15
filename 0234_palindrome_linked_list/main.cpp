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

        int* firstHalf = new int[nContent / 2];

        // Fill a buffer with first half of the linked list's values
        for (int i = 0; i < nContent / 2; i++)
        {
            /*
            // check for the nullptr too
            if (head->next == nullptr)
            {
                delete[] firstHalf;
                return 0; // Error
            }
            */
            firstHalf[i] = head->val;
            head = head->next;
        }

        (nContent % 2 == 1) ? head = head->next : head = head ; // We do not care about the middle

        for (int i = (nContent / 2) - 1; i >= 0; i--)
        {
            if (firstHalf[i] != head->val)
            {
                delete[] firstHalf;
                return 0;
            }

            head = head->next;
        }

        delete[] firstHalf;
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
    
    bool isPairsSame(ListNode* head, int n, int nContent_)
    {
        int i = 0;
        for (; i < n; i++)
        {
            // check for the nullptr too
            if (head->next == nullptr)
            {
                return 0; // Error
            }

            head = head->next;
        }

        int val1 = head->val;               // First value of the pair

        for (; i < nContent_ - 1 - n; i++)
        {
            // check for the nullptr too
            if (head->next == nullptr)
            {
                return 0; // Error
            }

            head = head->next;
        }

        if (val1 == head->val)
            return 1;
        else
            return 0;
    }

    bool getValues(ListNode* head, int storage[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            // check for the nullptr too
            if (head->next == nullptr)
            {
                return 0; // Error
            }
            storage[i] = head->val;
            head = head->next;
        }

        storage[size] = head->val;

        return 1;

    }

};

int main(void)
{
    Solution solution;

    /*
    ListNode node4 = ListNode(9);
    ListNode node3 = ListNode(5, &node4);
    ListNode node2 = ListNode(0, &node3);
    ListNode node1 = ListNode(4, &node2);
    ListNode node0 = ListNode(9, &node1); // head
    */
    
    
    ListNode node3 = ListNode(9);
    ListNode node2 = ListNode(5, &node3);
    ListNode node1 = ListNode(4, &node2);
    ListNode node0 = ListNode(9, &node1); // head
    

    printf("Address of head node is : %p\n", &node0);
    solution.isPalindrome(&node1);
    printf("Address of head node is : %p\n", &node0); // The solution method does not change the adr
    printf("Value of head.next.next is expected 0 and it is %d\n", node0.next->next->val);
    printf("Is the example pallindrome?\nAnswer is : %d\n", solution.isPalindrome(&node0));
    return 0;
}