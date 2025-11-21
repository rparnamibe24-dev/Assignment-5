#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

Node* createNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->next = nullptr;
    return n;
}

void insertEnd(int data) {
    Node* n = createNode(data);
    if (head == nullptr) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = n;
}

Node* reverseList(Node* head) {
    Node *prev = nullptr, *curr = head, *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);

    cout << "Original list:\n";
    display(head);

    head = reverseList(head);

    cout << "Reversed list:\n";
    display(head);

    return 0;
}
