#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to remove duplicates
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;

    ListNode* curr = head;

    while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp; // free memory
        } else {
            curr = curr->next;
        }
    }
    return head;
}

// Function to insert node at end
void insert(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
}

// Function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = NULL;

    // Example input: 1->1->2->3->3
    insert(head, 1);
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 3);

    cout << "Original List: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}