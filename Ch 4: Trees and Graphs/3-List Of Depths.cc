#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left, *right;

	TreeNode(int val){
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};


struct ListNode{
	int val;
	ListNode* next;

	ListNode(int val){
		this->val = val;
		next = nullptr;
	}
};

class Tree{
public:

	void dfs(TreeNode* root){
		if (!root) return;

		dfs(root->left);
		cout << root->val << " ";
		dfs(root->right);
	}

	void display(vector<ListNode*>& res){
		if (res.empty()) {
			cout << "Empty Array\n";
			return;
		}

		cout << "Level Wise LinkedLists are:\n";
		for (auto ll: res){
			ListNode* head = ll;
			while(head){
				cout << head->val << " ->";
				head = head->next;
			}

			cout << "NULL\n";
		}
	}

	TreeNode* helperBuild(vector<int>& arr, int start, int end){
		if (start > end){
			return NULL;
		}
		int mid = (start + end)/2;
		TreeNode* newRoot = new TreeNode(arr[mid]);

		newRoot->left = helperBuild(arr, start, mid-1);
		newRoot->right = helperBuild(arr, mid+1, end);
		return newRoot;
	}

	TreeNode* buildTree(vector<int>& arr){
		if (arr.empty()){
			return NULL;
		}
		return helperBuild(arr, 0, arr.size()-1);
	}


	vector<ListNode*> createLevelLinkedList(TreeNode* root){
		vector<ListNode*> ans;
		if (!root){
			return ans;
		}
		queue<TreeNode*> Q;
		Q.push(root);
		while(!Q.empty()){
			int n = Q.size();
			ListNode head(0);
			ListNode* dummy = &head;

			for(int i = 0; i<n; ++i){
				TreeNode* curr = Q.front();
				Q.pop();

				dummy->next = new ListNode(curr->val);
				dummy = dummy->next;

				if (curr->left){
					Q.push(curr->left);
				}

				if(curr->right){
					Q.push(curr->right);
				}
			}
			dummy->next = NULL;
			ans.push_back(head.next);
		}
		return ans;
	}
};

int main(void){
	Tree t;
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i<n; ++i) cin >> arr[i];

	TreeNode* root = t.buildTree(arr);
	vector<ListNode*> res = t.createLevelLinkedList(root);
	t.display(res);
}