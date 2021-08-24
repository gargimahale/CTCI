#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node(int _val): val(_val), next(nullptr) {}
};

class LinkedList{
	Node* head;
public:
	LinkedList(){
		head = nullptr;
	}

	void prependNode(int ele){
		Node* newHead = new Node(ele);
		newHead->next = head;
		head = newHead;
	}

	void appendNode(int ele){
		if (!head){
			head = new Node(ele);;
			return;
		}
		Node* current = head;
		while(current->next){
			current = current->next;
		}
		current->next = new Node(ele);
	}

	void display() {
		if (!head) {
			cout << "Linked List Empty\n";
			return;
		}
		Node* temp = head;
		while (temp) {
			cout << temp->val << "->";
			temp = temp->next;
		}
		cout << "NULL\n";
	}

	void deleteNode(int ele) {
		if (!head) return;

		if (ele == head->val){
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

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
	}
};

int main() {
	LinkedList ll;
	ll.prependNode(2);
	ll.appendNode(5);
	ll.appendNode(10);
	ll.prependNode(3);
	ll.deleteNode(3);
	ll.display();
}