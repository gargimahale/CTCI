#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left, *right, *parent;

	TreeNode(int val){
		this->val = val;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
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

	TreeNode* helperBuild(vector<int>& arr, int start, int end, TreeNode* parent){
		if (start > end){
			return NULL;
		}
		int mid = (start + end)/2;
		TreeNode* newRoot = new TreeNode(arr[mid]);
		newRoot->parent = parent;
		parent = newRoot;
		newRoot->left = helperBuild(arr, start, mid-1, parent);
		newRoot->right = helperBuild(arr, mid+1, end, parent);
		return newRoot;
	}

	TreeNode* buildTree(vector<int>& arr){
		if (arr.empty()){
			return NULL;
		}
		return helperBuild(arr, 0, arr.size()-1, NULL);
	}

	TreeNode* inorderSucessorBST(TreeNode* root){
		if (root->right){
			root = root->right;
			while(root->left){
				root = root->left;
			}
			return root;
		}

		while(root->parent){
			if (root->parent->left == root){
				return root->parent;
			}
			root = root->parent;
		}
		return nullptr;
	}
};

int main(void){
	Tree t;
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i<n; ++i) cin >> arr[i];
	TreeNode* root = t.buildTree(arr);
	cout << t.inorderSucessorBST(root)->val << "\n";
}