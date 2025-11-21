#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Create new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Insert before a value
void insertBefore(int value, int newValue) {
    Node* newNode = createNode(newValue);

    if (head == nullptr) return;

    if (head->data == value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;

    if (temp->next == nullptr) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert after a value
void insertAfter(int value, int newValue) {
    Node* temp = head;
    while (temp != nullptr && temp->data != value)
        temp = temp->next;

    if (temp == nullptr) return;

    Node* newNode = createNode(newValue);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning() {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteEnd() {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

// Delete a specific value
void deleteValue(int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;

    if (temp->next == nullptr) return;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Search for value
void search(int value) {
    Node* temp = head;
    int pos = 1;

    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found." << endl;
}

// Display list
void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int choice, value, newValue;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before a value\n";
        cout << "4. Insert after a value\n5. Delete from beginning\n6. Delete from end\n";
        cout << "7. Delete a value\n8. Search\n9. Display\n10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 3:
                cout << "Enter new value: ";
                cin >> newValue;
                cout << "Insert before which value? ";
                cin >> value;
                insertBefore(value, newValue);
                break;

            case 4:
                cout << "Enter new value: ";
                cin >> newValue;
                cout << "Insert after which value? ";
                cin >> value;
                insertAfter(value, newValue);
                break;

            case 5:
                deleteBeginning();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteValue(value);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;

            case 9:
                display();
                break;

            case 10:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
