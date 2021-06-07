//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

//Leetcode 559: Maximum Depth of N-ary Tree		7/6/2021		runtime: 62.99%, memory: 20.20%, time: O(n=count of nodes), space: O(h=max height)
int maxNum = 0;
int maxDepth(Node* root, int current = 0) {
	if (root == nullptr) return current;
	if (++current > maxNum) maxNum = current;
	for (int i = 0; i < root->children.size(); i++) {
		maxDepth(root->children[i], current);
	}

	return maxNum;

	//Leetcode god solution
	if (!root) return 0;
	int depth = 1;
	for (auto child : root->children)
		depth = max(depth, maxDepth(child));

	return depth;
}
