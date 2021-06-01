//https://leetcode.com/problems/increasing-order-search-tree/
//https://stackoverflow.com/questions/20125477/linked-list-insert-at-the-end-c

#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

//Leetcode 897: Increasing Order Search Tree		//25/5/21		runtime: 4ms, memory: 8mb, complexity: dk how to calculate, maybe O(h)
TreeNode* increasingBST(TreeNode* root) {
	TreeNode* current = root;

	TreeNode* newRoot = NULL;

	stack<TreeNode*> s;

	while (current || !s.empty())
	{
		/* Reach the left most Node of the
		   curr Node */
		while (current)
		{
			/* place pointer to a tree node on
			   the stack before traversing
			  the node's left subtree */
			s.push(current);
			current = current->left;
		}

		/* Current must be NULL at this point */
		current = s.top();
		s.pop();

		if (newRoot) {
			TreeNode* temp = newRoot;
			while (temp->right != NULL) temp = temp->right;
			temp->right = new TreeNode(current->val);
		}
		else {
			newRoot = new TreeNode(current->val);
		}

		/* we have visited the node and its
		   left subtree.  Now, it's right
		   subtree's turn */
		current = current->right;

	} /* end of while */

	return newRoot;
}


int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->left->right = new TreeNode(7);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);

	increasingBST(root);

	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
