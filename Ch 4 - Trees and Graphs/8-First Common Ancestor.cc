#include <vector>
#include <iostream>
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

class Tree{
public:

	void dfs(TreeNode* root){
		if (!root) return;
		dfs(root->left);
		cout << root->val << " ";
		dfs(root->right);
	}

	TreeNode* helperBuild(vector<int>& arr, int start, int end){
		if (start > end){
			return NULL;
		}

		int mid = (start + end)/2;
		TreeNode* newHead = new TreeNode(arr[mid]);
		newHead->left = helperBuild(arr, start, mid-1);
		newHead->right = helperBuild(arr, mid+1, end);
		return newHead;
	}

	TreeNode* buildTree(vector<int>& arr){
		if (arr.empty()){
			return NULL;
		}
		return helperBuild(arr, 0, arr.size()-1);
	}

	TreeNode* firstCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
		if (!root || root == p || root == q){
			return root;
		}

		TreeNode* l = firstCommonAncestor(root->left, p, q);
		TreeNode* r = firstCommonAncestor(root->right, p, q);

		return l && r ? root: l ? l: r;
	}
};

int main(void){
	Tree t;
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i<n; ++i){
		cin >> arr[i];
	}

	TreeNode* root = t.buildTree(arr);

	TreeNode* ans = t.firstCommonAncestor(root, new TreeNode(2), new TreeNode(6));
	cout << ans->val << "\n";
}