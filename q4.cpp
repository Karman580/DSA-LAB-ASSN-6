#include <iostream>
using namespace std;

class CharNode {
public:
    char data;
    CharNode *next, *prev;
    CharNode(char ch) {
        data = ch;
        next = prev = NULL;
    }
};

bool isPalindrome(CharNode* head) {
    if (!head) return true;
    CharNode* tail = head;
    while (tail->next) tail = tail->next;

    while (head && tail && head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}
