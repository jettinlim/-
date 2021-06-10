//https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/36153/My-concise-c%2B%2B-solution
//Leetcode 111: Minimum Depth of Binary Tree		9/6/2021		time&space: O(n=number of nodes)
int minDepth(TreeNode* root, int depth = 0) {
	if (!root) return depth;
	depth++;
	if (!root->left) return minDepth(root->right, depth);
	if (!root->right) return minDepth(root->left, depth);
	return min(minDepth(root->right, depth), minDepth(root->left, depth));
}
