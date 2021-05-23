//https://leetcode.com/problems/range-sum-of-bst/
//https://www.youtube.com/watch?v=7lvGUiOAZeE

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if (root == NULL)
            return 0;
        else if (root->val < low)       //if node value is smaller than low, no need to see the lefts anymore
            return rangeSumBST(root->right, low, high);
        else if (root->val <= high)     
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);        //add all the suitable node value in between
        else
            return rangeSumBST(root->left, low, high);      //if node value is higher than high, no need to see the rights anymore
    }
};
