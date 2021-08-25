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

void display(ListNode* head) {
    if (!head) return;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

// Fast Pointer Method
ListNode* deleteMiddleNode(ListNode* head) {
    ListNode* fast = head, *slow = head;
    ListNode* prev = NULL;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete(slow);
    return head;
}

int main(void) {
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        curr->next = new ListNode(temp);
        curr = curr->next;
    }
    display(head->next);
    cout << "New LinkedList: ";
    head = deleteMiddleNode(head->next);
    display(head);
}