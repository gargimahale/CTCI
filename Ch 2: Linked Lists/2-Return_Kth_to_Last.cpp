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

// TC: O(N), SC: O(1)

ListNode* kthToLast(ListNode* head, int k) {
	ListNode* p1 = head, *p2 = head;
	for (int i = 0; i < k; ++i) {
		if (p1 == NULL) return NULL;
		p1 = p1->next;
	}
	while (p1 != NULL) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

int main(void) {
	ListNode* head = new ListNode(0);
	ListNode* curr = head;
	int n, k;
	cin >> n >> k;
	while (n--) {
		int temp;
		cin >> temp;
		curr->next = new ListNode(temp);
		curr = curr->next;
	}
	display(head->next);
	cout << "New LinkedList: ";
	head = kthToLast(head->next, k);
	display(head);
}