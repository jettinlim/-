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

        while (!q.empty()) {
            int current_size = q.size();
            bool isX = false;
            bool isY = false;

            for (int i = 0; i < current_size; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->val == x) isX = true;
                if (current->val == y) isY = true;

                //current root have both left & right node
                if (current->left && current->right)
                    //they are siblings
                    if ((current->left->val == x && current->right->val == y) || (current->left->val == y && current->right->val == x))
                        return false;

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            if (isX && isY) return true;
        }

        return false;
    }
};
