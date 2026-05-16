#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to partition the list
ListNode* partition(ListNode* head, int x) {

    // Two dummy nodes
    ListNode* smallerHead = new ListNode(0);
    ListNode* greaterHead = new ListNode(0);

    ListNode* smaller = smallerHead;
    ListNode* greater = greaterHead;

    while (head != NULL) {

        if (head->val < x) {
            smaller->next = head;
            smaller = smaller->next;
        }
        else {
            greater->next = head;
            greater = greater->next;
        }

        head = head->next;
    }

    // End greater list
    greater->next = NULL;

    // Connect smaller and greater lists
    smaller->next = greaterHead->next;

    return smallerHead->next;
}

// Function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Creating linked list:
    // 1 -> 4 -> 3 -> 2 -> 5 -> 2

    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    cout << "Original List: ";
    printList(head);

    head = partition(head, x);

    cout << "Partitioned List: ";
    printList(head);

    return 0;
}