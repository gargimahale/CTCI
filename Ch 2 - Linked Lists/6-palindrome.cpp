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

ListNode* reverseLL(ListNode* head){
    ListNode* prev = nullptr;
    while(head){
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

void display(ListNode* head) {
    if (!head) return;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

bool palindrome(ListNode* head) {
    // stack<ListNode*> stk;
    // ListNode* temp = head;
    // while (temp) {
    //     stk.push(temp);
    //     temp = temp->next;
    // }
    // while (head) {
    //     if (stk.top()->val != head->val) {
    //         return false;
    //     }
    //     stk.pop();
    //     head = head->next;
    // }
    // return true;
    
    // OR
    if (!head){
        return false;
    }

    ListNode* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast){
        slow = slow->next;
    }
    slow = reverseLL(slow);

    fast = head;
    while(fast && slow){
        if (fast->val != slow->val){
            return false;
        }
        fast = fast->next;
        slow = slow->next;
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