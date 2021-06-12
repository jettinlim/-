//https://leetcode.com/problems/average-of-levels-in-binary-tree/

//Leetcode 637: Average Levels in Binary Tree		12/6/2021		time: O(n), space: O(n)
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        //To store result;
        vector<double> res;
        //For BFS iteration
        queue<TreeNode*> q;
        if(root) q.push(root);
        
        while(!q.empty()){
            long current_level_total_values = 0;           //long to prevent integer overflow
            int current_level_total_count = q.size();
            for(int i = 0; i < current_level_total_count; i++){
                TreeNode* current = q.front();
                current_level_total_values += current->val;     //sum the value of nodes in same level
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            res.push_back((double)current_level_total_values/current_level_total_count);    //store the average nodes values in same level, in decimal
        }
        
        return res;
    }
};
