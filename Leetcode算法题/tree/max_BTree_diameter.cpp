//https://leetcode.com/problems/diameter-of-binary-tree/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 543: Diameter of Binary Tree		  30/6/2021		time&space: O(n^2)
class Solution {
public:
    int maxNum = 0;
    int diameterOfBinaryTree(TreeNode* root){
        if (!root) return maxNum;
        int num = diameterOfSingleNode(root);
        if(num>maxNum) maxNum = num;
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxNum;
    }
    
    
    int diameterOfSingleNode(TreeNode* root) {
        return maxDepth(root->left) + maxDepth(root->right);
    }
    
    int maxDepth(TreeNode* root, int depth = 0) {
        if (root == nullptr) return depth;
        depth++;

        return max(maxDepth(root->right, depth), maxDepth(root->left, depth));
    }
};
