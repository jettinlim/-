//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcide 653: Two Sum - Input is a BST		17/6/2021		time: O(2n), space: O(n)
class Solution {
public:
    vector<int> store;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        store.push_back(root->val);
        if (existedVector(store, k - root->val)) return true;
        bool findLeft =  findTarget(root->left, k);
        bool findRight = findTarget(root->right, k);
        return findLeft || findRight;       //either one side have the equal sum node
    }
    
    bool existedVector(vector<int>& v, int num){    //check if sum value existed in vector
        for(int i = 0; i < v.size() - 1; i++){
            if(v[i] == num) return true;
        }
        return false;
    }
};
