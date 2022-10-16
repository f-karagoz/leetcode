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
     
    }
};

Solution solution;

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

    return 0;
}