//https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/ 

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 671: Second Minimum Node In Binary Tree		3/7/2021		time:O(n), space:O(h)
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> vec;
        storeVec(root, vec);
        sort( vec.begin(), vec.end() );
        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        return vec.size()>1 ? vec[1] : -1;
    }
    
    void storeVec(TreeNode* root, vector<int>& vec){
        if(!root) return;
        vec.push_back(root->val);
        storeVec(root->left, vec);
        storeVec(root->right, vec);
        return;
    }
};
