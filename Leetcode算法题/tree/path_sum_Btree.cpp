//https://leetcode.com/problems/path-sum/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 112: Path Sum		3/7/2021			time: O(n), space: O(h)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum, int sum=0) {
        if(!root) return false;
        sum += root->val;
        //reached at leaf node
        if(!root->left && !root->right)
            return sum == targetSum;
        return hasPathSum(root->left, targetSum, sum) || hasPathSum(root->right, targetSum, sum);
    }
};
