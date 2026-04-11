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

// Print linked list
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

// Remove Nth node from end
ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* first = head;
    ListNode* second = head;

    // Move first pointer n steps ahead
    for (int i = 0; i < n; i++) {
        first = first->next;
    }

    // If removing first node
    if (first == NULL) {
        return head->next;
    }

    // Move both pointers
    while (first->next != NULL) {

        first = first->next;
        second = second->next;
    }

    // Remove node
    second->next = second->next->next;

    return head;
}

int main() {

    ListNode* head = NULL;

    int n, value, removePos;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++) {

        cin >> value;
        head = insertNode(head, value);
    }

    cout << "Enter position from end to remove: ";
    cin >> removePos;

    head = removeNthFromEnd(head, removePos);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}