//https://leetcode.com/problems/maximum-depth-of-binary-tree/

//Leetcode 104: Maximum Depth of Binary Tree		8/6/2021		runtime: 29.84%, memory: 12.23%, time: O(n=number of nodes), space: O(h=max height)
int maxDepth(TreeNode* root, int depth = 0) {
	if (root == nullptr) return depth;
	depth++;

	return max(maxDepth(root->right, depth), maxDepth(root->left, depth));
}

//Leetcode god solution
int maxDepth(TreeNode* root) {
	return root ? max(maxDepth(root->right), maxDepth(root->left)) + 1 : 0;
}
