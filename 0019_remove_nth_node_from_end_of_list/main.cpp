#include <iostream>
#include <queue>
using namespace std;

/*
Given the head of a linked list,
remove the nth node from the end of the list and return its head.
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* head_ = head;
        queue<ListNode*> lastNNodes;

        for (int i = 0; head->next != NULL; ++i)
        {
            lastNNodes.push(head);

            // n + 1 elements stored in the queue
            if (i > n - 1)
                lastNNodes.pop();

            head = head->next;
        }

        lastNNodes.front()->next = lastNNodes.front()->next->next;
        return head_;

    }
};

Solution sol;

int main(void)
{
    /*
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
    */

    ListNode node4 = ListNode(5);
    ListNode node3 = ListNode(4, &node4);
    ListNode node2 = ListNode(3, &node3);
    ListNode node1 = ListNode(2, &node2);
    ListNode node0 = ListNode(1, &node1); // head

    ListNode* test = &node0;

    while (test != NULL)
    {
        cout << test->val << ", ";
        test = test->next;
    }
    cout << endl;

    ListNode* result = sol.removeNthFromEnd(&node0, 2);

    while (result != NULL)
    {
        cout << result->val << ", ";
        result = result->next;
    }    
    cout << endl;

    return 0;
}