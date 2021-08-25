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
};

int main(void){
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i<n; ++i) cin >> arr[i];
	Tree t;
	TreeNode* root = t.buildTree(arr);
	t.dfs(root);
}