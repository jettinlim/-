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
        
        queue<TreeNode*> q;
        
        if(root) 
            q.push(root);
        
        while(!q.empty()){
            int is_leaf_count = 0;
            int queue_count = q.size();
            int sum = 0;
            
            for(int i = 0; i < queue_count; i++){
                TreeNode* current = q.front();
                q.pop();
                if(!current->right && !current->left){
                    is_leaf_count++;
                    sum += current->val;
                } 
                else{
                    if(current->right) q.push(current->right);
                    if(current->left) q.push(current->left);
                }       
            }
            
            if(is_leaf_count == queue_count) 
                return sum;
        }
        
        return 0;
    }
};
