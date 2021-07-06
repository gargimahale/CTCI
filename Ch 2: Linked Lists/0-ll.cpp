#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node(int _val) {
		val = _val;
		next = NULL;
	}
};

void display(Node* head) {
	if (!head) return;
	Node* temp = head;
	while (temp->next) {
		cout << temp->next->val << " ";
		temp = temp->next;
	}
	cout << "\n";
}

Node* deleteNode(Node* head, int ele) {
	if (!head) return head;
	Node* temp = head;
	while (temp->next) {
		if (temp->next->val == ele) {
			Node* curr = temp->next;
			temp->next = temp->next->next;

			// frees memory
			delete(curr);
		}
		else {
			temp = temp->next;
		}
	}
	return head;
}

int main() {
	Node* head = new Node(0);
	Node* curr = head;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;

		// apppends to tail
		curr->next = new Node(temp);
		curr = curr->next;
	}
	display(head);
	int k;
	cin >> k;
	head = deleteNode(head, k);
	cout << "Updated LinkedList After Deletion:" << "\n";
	display(head);
	return 0;
}