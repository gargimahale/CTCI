#include <iostream>
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

	bool helperCheckSubTree(TreeNode* t1, TreeNode* t2){
		if (!t1 && !t2) return true;
		if (!t1 || !t2) return false;

		if (t1->val != t2->val) return false;

		return helperCheckSubTree(t1->left, t2->left) && helperCheckSubTree(t1->right, t2->right);
	}

	bool checkSubTree(TreeNode* t1, TreeNode* t2){
		if (!t1){
			return false;
		}

		return helperCheckSubTree(t1, t2) || helperCheckSubTree(t1->left, t2) || helperCheckSubTree(t1->right, t2);
	}
};

int main(void){
	int n, m;
	cin >> n >> m;
	vector<int> t1(n), t2(m);
	for (int i = 0; i<n; ++i) cin >> t1[i];

	for (int i = 0; i<m; ++i) cin >> t2[i];

	Tree t;
	TreeNode* r1 = t.buildTree(t1);
	TreeNode* r2 = t.buildTree(t2);

	cout << t.checkSubTree(r1, r2) << "\n";
}