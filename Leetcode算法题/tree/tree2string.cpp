//https://leetcode.com/problems/construct-string-from-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
//Leetcode 606: Construct String from Binary Tree		19/6/2021	time: O(n), space: O(h)
class Solution {
public:
    string res = "";
    string tree2str(TreeNode* root, int level=0) {
        if(!root) return "";
        level++;
        if(level==1){
            res += to_string(root->val);
            if(!root->left && root->right) res += "()";
            tree2str(root->left, level);
            tree2str(root->right, level);
        }
        else{
            res += '(' + to_string(root->val);
            if(!root->left && root->right) res += "()";
            tree2str(root->left, level);
            tree2str(root->right, level);
            res += ')';
        }   
        return res;
    }
};
