//https://leetcode.com/problems/merge-two-binary-trees/
//https://www.geeksforgeeks.org/merge-two-binary-trees-node-sum/#:~:text=Given%20two%20binary%20trees.,the%20node%20of%20new%20tree.

#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int travelTree(TreeNode* root, int level = 0) {		//25/5/21		DFS traversal

	string temp = "";

	if (root == NULL)
		cout << to_string(level) + " none\n";
	else {
		travelTree(root->left, level + 1);
		travelTree(root->right, level + 1);
		cout << to_string(level) + ": " + to_string(root->val) + "\n";
	}

	return 0;
}

TreeNode* mergeTree(TreeNode* root1, TreeNode* root2) {		//25/5/21		runtime: 93.84%, memory: 55.23%,	complexity: NP

	if (root1 && root2) {
		root1->val += root2->val;
		root1->left = mergeTree(root1->left, root2->left);
		root1->right = mergeTree(root1->right, root2->right);
		return root1;
	}
	else
		return root1 ? root1 : root2;

	return root1;
}


int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	TreeNode* root1 = new TreeNode(1);
	root1->left = new TreeNode(3);
	root1->left->left = new TreeNode(5);
	root1->left->right = new TreeNode(3);
	root1->right = new TreeNode(2);

	TreeNode* root2 = new TreeNode(2);
	root2->left = new TreeNode(1);
	root2->left->right = new TreeNode(4);
	root2->left->left = new TreeNode(3);
	root2->right = new TreeNode(3);
	root2->right->right = new TreeNode(7);

	cout << travelTree(mergeTree(root1, root2));


	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
