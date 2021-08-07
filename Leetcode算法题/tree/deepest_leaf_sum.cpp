//https://leetcode.com/problems/deepest-leaves-sum/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        
        if(root) q.push(root);
        
        while(!q.empty()){
            int queue_count = q.size();
            sum = 0;
            
            for(int i = 0; i < queue_count; i++){
                TreeNode* current = q.front();
                q.pop();
                sum += current->val;
                if(current->right) q.push(current->right);
                if(current->left) q.push(current->left);
            }
        }
        
        return sum;
    }
};
