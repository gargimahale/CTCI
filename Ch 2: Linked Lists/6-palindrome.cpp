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

bool palindrome(ListNode* head) {
    stack<ListNode*> stk;
    ListNode* temp = head;
    while (temp) {
        stk.push(temp);
        temp = temp->next;
    }
    while (head) {
        if (stk.top()->val != head->val) {
            return false;
        }
        stk.pop();
        head = head->next;
    }
    return true;
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
    cout << "Linked List: ";
    display(head->next);
    cout << palindrome(head->next) << "\n";
}