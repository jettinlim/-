//https://leetcode.com/problems/n-ary-tree-level-order-traversal/

struct Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//Leetcode 429: N-ary Tree Level Order Traversal		13/6/2021		time: O(n), space: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      
        vector<vector<int>> res;                
        queue<Node*> q;
        
        if(root) q.push(root);
        
        while(!q.empty()){
            vector<int> temp = {};              //clear temp vector to store new current node values
            int size = q.size();
            for(int i = 0; i < size; i++){      //size = node count in current level
                Node* current = q.front();
                q.pop();                        //remove current level nodes from queue to keep track level
                temp.push_back(current->val);   //store all current level node val in temp
                for(Node* child: current->children) q.push(child);  //store every children of current node into the queue
            }
            res.push_back(temp);            //store temp in result
        }
        
        return res;
    }
};
