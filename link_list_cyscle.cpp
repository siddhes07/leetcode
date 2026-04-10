#include <iostream>
using namespace std;

// Node structure
struct ListNode {

    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Insert node at end
ListNode* insertNode(ListNode* head, int value) {

    if (head == NULL)
        return new ListNode(value);

    ListNode* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new ListNode(value);

    return head;
}

// Function to create cycle (for testing)
void createCycle(ListNode* head, int pos) {

    if (pos == -1)
        return;

    ListNode* temp = head;
    ListNode* cycleNode = NULL;

    int count = 1;

    while (temp->next != NULL) {

        if (count == pos)
            cycleNode = temp;

        temp = temp->next;
        count++;
    }

    temp->next = cycleNode;
}

// Detect cycle function
bool hasCycle(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {

    ListNode* head = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++) {

        cin >> value;
        head = insertNode(head, value);
    }

    int pos;

    cout << "Enter position to create cycle (-1 for no cycle): ";
    cin >> pos;

    createCycle(head, pos);

    if (hasCycle(head))
        cout << "Cycle detected in linked list" << endl;

    else
        cout << "No cycle in linked list" << endl;

    return 0;
}