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

// TC: O(max(n, m)), SC: O(max(n, m))
ListNode* sumOfLists(ListNode* n1, ListNode* n2) {
    if (!n1) return n2;
    if (!n2) return n1;
    ListNode* newHead = new ListNode(0);
    ListNode* temp = newHead;
    int c = 0;
    while (n1 || n2 || c) {
        c += (n1 ? n1->val : 0) + (n2 ? n2->val : 0);
        newHead->next = new ListNode(c % 10);
        c /= 10;
        newHead = newHead->next;
        n1 = n1 ? n1->next : NULL;
        n2 = n2 ? n2->next : NULL;
    }
    return temp->next;
}

int main(void) {
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    ListNode* head1 = new ListNode(0);
    ListNode* curr1 = head1;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        curr->next = new ListNode(temp);
        curr = curr->next;
    }
    cout << "Linked List 1: ";
    display(head->next);

    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        curr1->next = new ListNode(temp);
        curr1 = curr1->next;
    }
    cout << "Linked List 2: ";
    display(head1);


    head = sumOfLists(head, head1);
    cout << "Addition: ";
    display(head->next);
}