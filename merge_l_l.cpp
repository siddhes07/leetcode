#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeLists(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
}

void insert(Node*& head, int value) {
    Node* newNode = new Node{value, NULL};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node *l1 = NULL, *l2 = NULL;
    int n, x;

    cout << "Enter nodes for List1: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(l1, x);
    }

    cout << "Enter nodes for List2: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(l2, x);
    }

    Node* merged = mergeLists(l1, l2);

    cout << "Merged List:\n";
    display(merged);
}