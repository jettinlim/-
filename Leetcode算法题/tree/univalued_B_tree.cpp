
//Leetcode 965: Univalued Binary Tree			10/6/2021		time&space: O(n=number of nodes)
bool isUnivalTree(TreeNode* root) {		
	if (!root) return true;
	if (root->left && root->left->val != root->val) return false;
	if (root->right && root->right->val != root->val) return false;
	return isUnivalTree(root->right) && isUnivalTree(root->left);
}
