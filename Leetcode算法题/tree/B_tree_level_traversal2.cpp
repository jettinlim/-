//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 107: Binary Tree Level Order Traversal II		14/6/2021		time&space: O(n=count of nodes)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            vector<int> temp = {};
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* current = q.front();
                temp.push_back(current->val);
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            res.insert(res.begin(), temp);    //just reverse insert into result vector, nothing special actually
        }
              
      return res;
    }
};
