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

// TC: O(N), SC: O(1)
ListNode* partionedLinkedList(ListNode* node, int p) {
    ListNode* head = node, *tail = node;
    while (node) {
        ListNode* next = node->next;

        // for elements strictly smaller than p
        if (node->val < p) {
            node->next = head;
            head = node;
        }

        // for elements larger than p
        else {
            tail->next = node;
            tail = node;
        }
        node = next;
    }
    tail->next = NULL;
    return head;
}

int main(void) {
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        curr->next = new ListNode(temp);
        curr = curr->next;
    }
    display(head->next);
    cout << "New LinkedList: ";
    head = partionedLinkedList(head->next, p);
    display(head);
}