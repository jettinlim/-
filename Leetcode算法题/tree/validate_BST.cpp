//https://leetcode.com/problems/validate-binary-search-tree/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 98: Validate Binary Search Tree		14/6/2021	time&space: O(n=count of nodes)
class Solution {
public:
  vector<int> v;
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    bool left = isValidBST(root->left);
    v.push_back(root->val);
    if (v.size() >= 2 && v.back() <= v[v.size() - 2]) return false;   //store every nodes value inorderly,then compare with previous value, if not larger then it is not a BST
    bool right = isValidBST(root->right);
    return left && right;
  }
};

//Solution without using vector
TreeNode* prev = NULL;
bool isValidBST(TreeNode* root) {
    if (!root) return true;
    bool left = isValidBST(root->left);
    if(prev && root->val<= prev->val) return false;
    else prev = root;
    bool right = isValidBST(root->right);
    return left && right;
}


//Leetcode god solution
bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) return true;
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}
