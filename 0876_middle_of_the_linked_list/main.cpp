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
    /*
    * First solution ( BETTER ONE )
    
    ListNode* middleNode(ListNode* head)
    {
        int sgn = 0;
        ListNode* result = head;

        while (head->next != NULL)
        {
            head = head->next;
            sgn = !sgn;
            if (sgn)
                result = result->next;
        }

        return result;

    }
    */

    ListNode* middleNode(ListNode* head)
    {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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
    cout << "Middle node is: " << solution.middleNode(&node0)->val << endl;
    return 0;
}