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

// Solution with temp buffer - TC: O(N), SC: O(N)
// Can Also be implemenetd using unordered_map <ele, count(ele)>
/*
void deleteDuplicates_withBuffer(ListNode* head) {
    if (!head) return;
    unordered_set<int> S;
    ListNode* curr = head, *prev = NULL;
    while (curr) {
        if (S.find(curr->val) != S.end()) {
            prev->next = curr->next;
            delete(curr);
        }
        else {
            S.insert(curr->val);
            prev = curr;
        }
        curr = prev->next;
    }
}
*/

// Solution without temp buffer - TC: O(N^2), SC: O(1)
void deleteDuplicates_withoutBuffer(ListNode* head) {
    if (!head) return;
    ListNode* curr = head;
    while (curr) {
        ListNode* fast = curr;
        while (fast->next) {
            if (fast->next->val == curr->val) {
                ListNode* temp = fast->next;
                fast->next = fast->next->next;
                delete(temp);
            } else {
                fast = fast->next;
            }
        }
        curr = curr->next;
    }
}

void display(ListNode* head) {
    if (!head) return;
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "\n";
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

    cout << "Linked List Before Deleting Duplicates:" << "\n";
    display(head);

    cout << "Linked List After Deleting Duplicates:" << "\n";
    // deleteDuplicates_withBuffer(head->next);
    deleteDuplicates_withoutBuffer(head->next);
    display(head);
}