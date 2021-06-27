//https://leetcode.com/problems/sum-of-left-leaves/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 404: Sum of Leaves		27/6/2021		time: O(n), space: O(n)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //Prepare a queue for bfs traversal
        queue<TreeNode*> q;
        q.push(root);
        
        //declare initial sum of root value
        int sum = 0;
        
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            //Only do things on left node
            if(current->left){
                q.push(current->left);
                //if left node is a leaf(no children), sum it up
                if(!current->left->left && !current->left->right) 
                    sum += current->left->val;
            }
            if(current->right) q.push(current->right);
        }
        
        return sum;
    }
};
