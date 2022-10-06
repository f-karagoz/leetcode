#include <iostream>
using namespace std;

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
    ListNode* middleNode(ListNode* head)
    {
        int sizeLL = nNodes(head);
        int middleIndex = sizeLL / 2 + 1;

        ListNode* result = head;

        for (int i = 0; i < middleIndex-1; i++)
            result = result->next;

        return result;

    }
    
    int nNodes(ListNode* head)
    {
        int n = 1;

        while (head->next != NULL)
        {
            head = head->next;
            n++;
        }

        return n;
    }

};

Solution solution;

int main(void)
{
    /*
    ListNode node3 = ListNode(4);
    ListNode node2 = ListNode(3, &node3);
    ListNode node1 = ListNode(2, &node2);
    ListNode node0 = ListNode(1, &node1); // head
    */

    ListNode node4 = ListNode(5);
    ListNode node3 = ListNode(4, &node4);
    ListNode node2 = ListNode(3, &node3);
    ListNode node1 = ListNode(2, &node2);
    ListNode node0 = ListNode(1, &node1); // head


    cout << "Address of head node is :" << &node0 << endl;
    cout << "Size of Linked List is: " << solution.nNodes(&node0) << endl;
    cout << "Middle node is: " << solution.middleNode(&node0)->val << endl;
    return 0;
}