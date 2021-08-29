#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;

// delete and random node

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
		cout << root->val << " ";
		dfs(root->left);
		dfs(root->right);
	}

	TreeNode* addNewNode(TreeNode* root, int val){
		if (!root) return new TreeNode(val);
		if (val > root->val){
			root->right = addNewNode(root->right, val);
		}
		if (val <= root->val){
			root->left = addNewNode(root->left, val);
		}
		return root;
	}

	TreeNode* insertIntoBST(TreeNode* root, int val){
		if (!root) return new TreeNode(val);
		return addNewNode(root, val);
	}

	TreeNode* findMin(TreeNode* root){
		while(root->left){
			root = root->left;
		}
		return root;
	}

	TreeNode* deleteFromBST(TreeNode* root, int key){
		if (!root){
			return NULL;
		}

		else if (key < root->val){
			root->left = deleteFromBST(root->left, key);
		}
		else if (key > root->val){
			root->right = deleteFromBST(root->right, key);
		}
		else{
			if (!root->left && !root->right){
				delete root;
				root = NULL;
			}
			else if (!root->left){
				TreeNode* tmp = root;
				root = root->right;
				delete tmp;
			}
			else if (!root->right){
				TreeNode* tmp = root;
				root = root->left;
				delete tmp;
			}
			else{
				TreeNode* tmp = findMin(root->right);
				root->val = tmp->val;
				root->right = deleteFromBST(root->right, tmp->val);
			}
		}
		return root;
	}

	// TreeNode* getRandomNode(int val){

	// }
};
    
int main(void){
	Tree t;
	TreeNode* root = nullptr;
	int nodes, n, data;
	cin >> nodes;
	for (int i = 0; i < nodes; ++i){
		cin >> data;
		root = t.insertIntoBST(root, data);
	}

	
	cout << "before deletion\n";
	t.dfs(root);
	cout << "\n";
	cin >> n;
	root = t.deleteFromBST(root, n);
	cout << "after deletion\n";
	t.dfs(root);
	// cout << t.getRandomNode();
}