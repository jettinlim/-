//https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Leetcode 1379: Find a Corresponding Node of a Binary Tree in a Clone of That Tree			8/8/2021			time, space: O(h), DFS
class Solution {
public:
    TreeNode* temp;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original && !cloned) return cloned;
        if(cloned->val == target->val) temp = cloned;
        getTargetCopy(original->left, cloned->left, target);
        getTargetCopy(original->right, cloned->right, target);
        return temp;
    }
};
