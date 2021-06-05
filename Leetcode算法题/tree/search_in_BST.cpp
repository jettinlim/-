//https://leetcode.com/problems/search-in-a-binary-search-tree/
//https://leetcode.com/problems/search-in-a-binary-search-tree/discuss/139687/Concise-iterative-solution-(C%2B%2B)

//Leetcode 700: Search in a Binary Search Tree			5/6/2021
TreeNode* searchBST(TreeNode* root, int val) {

	//Binary Tree method(dfs all the nodes until meet the val)								runtime: 36.00%, memory: 92.49%, complexity: O(n=number of nodes)
	TreeNode* current = root;

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
		if (current->val == val) return current;
		s.pop();

		/* we have visited the node and its
		   left subtree.  Now, it's right
		   subtree's turn */
		current = current->right;

	} /* end of while */

	return NULL;

	//BST method(BST root always greater than left & smaller than right)										runtime: 16.49%, memory: 19.92%, complexity: <= O(n=number of nodes)
	while (root && root->val != val) {
		if (root->val < val) {
			root = root->right;
		}
		else {
			root = root->left;
		}
	}

	return root;
}

int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	//Binary Tree
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(7);

	cout << searchBST(root, 2)->val;

	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
