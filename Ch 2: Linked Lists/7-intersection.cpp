#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int _val) {
        val = _val;
        next = NULL;
    }
};

int findIntersection(ListNode* l1, ListNode* l2) {
    ListNode* a = l1, *b = l2;
    while (a != b) {
        a = a == NULL ? b : a->next;
        b = b == NULL ? a : b->next;
    }
    return a->val;
}