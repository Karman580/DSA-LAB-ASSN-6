#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() { head = NULL; }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    // Insert after a specific node
    void insertAfter(int key, int val) {
        Node* temp = head;
        if (!head) return;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found!\n";
    }

    // Delete specific node
    void deleteNode(int key) {
        if (head == NULL) return;

        Node *curr = head, *prev = NULL;

        // If head is to be deleted
        if (curr->data == key) {
            Node* last = head;
            while (last->next != head)
                last = last->next;
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }
            last->next = head->next;
            delete head;
            head = last->next;
            return;
        }

        // Search node to delete
        do {
            prev = curr;
            curr = curr->next;
        } while (curr != head && curr->data != key);

        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
        } else {
            cout << "Node " << key << " not found!\n";
        }
    }

    // Search for a node
    bool search(int key) {
        if (head == NULL) return false;
        Node* temp = head;
        do {
            if (temp->data == key) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; // Repeat head value at end
    }
};

int main() {
    CircularLinkedList cll;
    int choice, val, key;

    do {
        cout << "\n----- Circular Linked List Menu -----\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After a Node\n";
        cout << "4. Delete a Node\n5. Search a Node\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            cll.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            cll.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key and value: ";
            cin >> key >> val;
            cll.insertAfter(key, val);
            break;
        case 4:
            cout << "Enter node to delete: ";
            cin >> val;
            cll.deleteNode(val);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (cll.search(val) ? "Found\n" : "Not Found\n");
            break;
        case 6:
            cll.display();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
