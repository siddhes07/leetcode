#include <iostream>
using namespace std;

// Node structure
struct ListNode
{
    int data;
    ListNode* next;

    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert at end
void insert(ListNode*& head, int val)
{
    if(head == NULL)
    {
        head = new ListNode(val);
        return;
    }

    ListNode* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new ListNode(val);
}

// Function to find middle node
ListNode* middleNode(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    ListNode* head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> value;
        insert(head, value);
    }

    ListNode* mid = middleNode(head);

    cout << "Middle node value = " << mid->data << endl;

    return 0;
}