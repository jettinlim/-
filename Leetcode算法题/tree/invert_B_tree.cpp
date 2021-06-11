//https://leetcode.com/problems/invert-binary-tree/

//Leetcode 226: Invert Binary Tree			11/6/2021			

/*Time complexity: O(n) where n is the number of nodes, and each nodes will sure be visited one time
Space complexity: O(h) where h is the height of the tree, O(h) function calls will be placed on the memory stack during recursion*/

TreeNode* invertBinaryTree(TreeNode* root) {
	if (root == nullptr) return root;
	TreeNode* tempRoot = root->right;
	root->right = root->left;
	root->left = tempRoot;
	invertBinaryTree(root->right);
	invertBinaryTree(root->left);
	return root;
}
