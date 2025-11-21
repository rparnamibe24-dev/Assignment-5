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

// Insert at end helper
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

int countAndDelete(int key) {
    int count = 0;

    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    if (head == nullptr) return count;

    Node* curr = head;

    while (curr->next != nullptr) {
        if (curr->next->data == key) {
            Node* del = curr->next;
            curr->next = del->next;
            delete del;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(1);
    insertEnd(2);
    insertEnd(1);
    insertEnd(3);
    insertEnd(1);

    cout << "Original list:\n";
    display();

    int key = 1;
    int occurrences = countAndDelete(key);

    cout << "Occurrences of " << key << ": " << occurrences << endl;

    cout << "List after deletion:\n";
    display();

    return 0;
}
