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

int findMiddle() {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);

    cout << "Middle element: " << findMiddle() << endl;

    return 0;
}
