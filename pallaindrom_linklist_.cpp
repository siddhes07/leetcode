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

class Solution {
public:

    // Reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    // Check palindrome
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* secondHalf = reverse(slow->next);

        ListNode* firstHalf = head;

        // Compare both halves
        while(secondHalf != NULL) {
            if(firstHalf->val != secondHalf->val)
                return false;

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};


// Function to create linked list from user input
ListNode* createList(int n) {

    if(n <= 0)
        return NULL;

    int value;
    cout << "Enter value 1: ";
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    for(int i = 2; i <= n; i++) {
        cout << "Enter value " << i << ": ";
        cin >> value;

        temp->next = new ListNode(value);
        temp = temp->next;
    }

    return head;
}


// Print linked list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


// Main function
int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = createList(n);

    cout << "Your Linked List: ";
    printList(head);

    Solution obj;

    if(obj.isPalindrome(head))
        cout << "Linked List palindrome aahe ✅" << endl;
    else
        cout << "Linked List palindrome nahi ❌" << endl;

    return 0;
}