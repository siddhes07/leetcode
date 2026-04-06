#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, NULL}}}};
    
    cout << "Original: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed: ";
    printList(head);

    return 0;
}
