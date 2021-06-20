//https://leetcode.com/problems/minimum-absolute-difference-in-bst/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 530: Minimum Absolute Difference in BST		20/6/2021		time: O(2n), space: O(h+n)
class Solution {
public:
    int minNum = 10000;
    vector<int> findMinNum;
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        getMinimumDifference(root->left);
        getMinimumDifference(root->right);
        getMinNum(root->val);
        return minNum;
    }
    
    void getMinNum(int rootVal){
        for(int n: findMinNum){
            if(n > rootVal && n-rootVal < minNum) minNum = n-rootVal;
            else if(n < rootVal && rootVal-n < minNum) minNum = rootVal-n;
        }
        findMinNum.push_back(rootVal);
    }
};
