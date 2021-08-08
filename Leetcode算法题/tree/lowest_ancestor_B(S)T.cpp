//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Leetcode 235: Lowest Common Ancestor of a Binary Search Tree		24/6/2021	      time&space:O(n^2)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(root);
        stack<TreeNode*> s;
        
        //bfs to store nodes in queue in ascending, then store in stack in descending order(find ansestor from bottom)
        while(!que.empty()){
            TreeNode* current = que.front();
            que.pop();
            s.push(current);
            if(current->left) que.push(current->left);
            if(current->right) que.push(current->right);
        }
        
        //traversal in stack to find the ancestor
        while(!s.empty()){
            TreeNode* current = s.top();
            s.pop();
            if (isLowestCommonAncestor(current, p, q)) return current;
        }
        
        return NULL;
    }
    
    //bfs to find if the 2 nodes exist
    bool isLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        
        queue<TreeNode*> que;
        que.push(root);
        
        bool existP = false;
        bool existQ = false;
        
        //if this root consist of this two nodes no matter in which position, return true
        while(!que.empty()){
            TreeNode* current = que.front();
            que.pop();
            if(current == p) existP = true;
            if(current == q) existQ = true;
            if(current->left) que.push(current->left);
            if(current->right) que.push(current->right);
        }
        
        return existP && existQ;
    }
    
};

//Forgotten it is BST		25/6/2021	time:O(n/2), space: O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if root val larger than both, go right
        if(root->val > p->val && root->val > q->val)    
            return lowestCommonAncestor(root->left, p ,q);
        //if root val smaller than both, go left
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        //if root val between them, this is the lowest common ancestor
        return root;
    }
};
