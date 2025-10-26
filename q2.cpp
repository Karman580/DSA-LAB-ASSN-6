#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode *next, *prev;

    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
    DNode* head;

public:
    DoublyLinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int key) {
        if (!head) return;
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
    }

    bool search(int key) {
        DNode* temp = head;
        while (temp) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
