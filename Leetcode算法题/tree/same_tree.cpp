//https://leetcode.com/problems/same-tree/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 100: Same Tree		23/6/2021	time:O(n), space: O(h)		//travel 2 tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //both is null
        if(!p && !q) return true;
        //only one is null
        else if (!p && q || p && !q) return false;
        //both not null, but not same value
        else if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
