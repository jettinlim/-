//https://leetcode.com/problems/symmetric-tree/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 101: Symmetric Tree		1/7/2021		time&space: O(n)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, invertTree(root->right));
    }
    
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        if(root1->val != root2->val) return false;
        return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
    }
    
    TreeNode* invertTree(TreeNode* root){
        if(!root) return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
