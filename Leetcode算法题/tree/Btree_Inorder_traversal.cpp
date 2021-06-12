//https://leetcode.com/problems/binary-tree-inorder-traversal/

//Leetcode 94: Binary Tree Inorder Traversal		11/6/2021
/*Time complexity will be O(n) which n denotes the counts of node od this tree.
Space complexity will be O(h) since we need h calls for reaching leaves h denotes to path length of the longest path in this tree. Or you can say O(logN) because h is bonded by  logN.*/
vector<int> store;
vector<int> inorderTraversal(TreeNode* root) {
	if (!root) return {};
	inorderTraversal(root->left);
	store.push_back(root->val);
	inorderTraversal(root->right);
	return store;
}
