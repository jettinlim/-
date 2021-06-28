//https://leetcode.com/problems/cousins-in-binary-tree/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 993: Cousins in Binary Tree			28/6/2021		time&space: O(n), vector and stack	
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = x+y;
        
        while(!q.empty()){
            int current_size = q.size();
            //clear vector
            vector<int> v = {};
            for(int i = 0; i < current_size; i++){
                TreeNode* current = q.front();
                q.pop();
                
                //current root have both left & right node
                if(current->left && current->right)
                    //they are siblings
                    if (sum-current->left->val==current->right->val || sum-current->right->val==current->left->val) return false;
                
                if(current->left){
                    q.push(current->left);
                    v.push_back(current->left->val);
                } 
                if(current->right){
                    q.push(current->right);
                    v.push_back(current->right->val);
                }
            }
            
	    //check existence in vector
            if(std::find(v.begin(), v.end(), x) != v.end())
            {
              if(std::find(v.begin(), v.end(), y) != v.end())
                {
                    //Both value are at the same level
                    return true;
                } 
            } 
        }
        
        return false;
    }
};
