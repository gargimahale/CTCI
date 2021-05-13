#include <bits/stdc++.h>
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

int loopDetection(ListNode* head) {
    ListNode* fast = head, *slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // collision
            break;
        }
    }

    // error check
    if (fast == NULL || fast->next == NULL) {
        return -1;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return fast->val;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        curr->next = new ListNode(temp);
        curr = curr->next;
    }
    cout << "Linked List: ";
    display(head->next);

    cout << loopDetection(head->next) << "\n";
}