//https://leetcode.com/problems/leaf-similar-trees/
//https://zxi.mytechroad.com/blog/tree/leetcode-872-leaf-similar-trees/

//Leetcode 872: Leaf Similar Trees		15/6/2021		time&space: O(n1+n2)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;    //for storing to compare
        getLeaf(root1, v1);
        getLeaf(root2, v2);
        
        return v1==v2;
    }
    
    void getLeaf(TreeNode* root, vector<int>& v){
        if(!root) return;
        if(!root->left && !root->right) v.push_back(root->val);
        getLeaf(root->left, v);
        getLeaf(root->right,v); 
    }    
};

//second solution
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	stack<TreeNode*> s1, s2;
	vector<int> res1, res2;

	TreeNode* current = root1;
	while (current || !s1.empty())
	{
		/* Reach the left most Node of the
		   curr Node */
		while (current)
		{
			/* place pointer to a tree node on
			   the stack before traversing
			  the node's left subtree */
			s1.push(current);
			current = current->left;
		}

		/* Current must be NULL at this point */
		current = s1.top();
		if (!current->left && !current->right) res1.push_back(current->val);
		s1.pop();

		/* we have visited the node and its
		   left subtree.  Now, it's right
		   subtree's turn */
		current = current->right;

	} /* end of while */

	current = root2;
	while (current || !s2.empty())
	{
		/* Reach the left most Node of the
		   curr Node */
		while (current)
		{
			/* place pointer to a tree node on
			   the stack before traversing
			  the node's left subtree */
			s2.push(current);
			current = current->left;
		}

		/* Current must be NULL at this point */
		current = s2.top();
		if (!current->left && !current->right) res2.push_back(current->val);
		s2.pop();

		/* we have visited the node and its
		   left subtree.  Now, it's right
		   subtree's turn */
		current = current->right;

	} /* end of while */


	return res1 == res2;
}
