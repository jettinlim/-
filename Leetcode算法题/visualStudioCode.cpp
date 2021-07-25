#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

//Leetcode 1309: Decrypt String from Alphabet to Integer Mapping		8/5/2021		runtime: 4ms,	memory: 6.4mb
string freqAlphabets(string s) {

	//Mapping method
	map<string, char> decrypt;
	int count = 1;
	string result;

	for (char i = 'a'; i <= 'z'; i++) {
		if (i < 'j')
			decrypt[to_string(count++)] = i;
		else
			decrypt[to_string(count++) + '#'] = i;
	}

	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '#') {
			string temp = string(1, s[i - 2]) + string(1, s[i - 1]) + '#';		//avoid ascii
			i -= 2;
			result.insert(0, string(1, decrypt[temp]));
		}
		else
			result.insert(0, string(1, decrypt[string(1, s[i])]));
	}

	return result;
}

string freqAlphabets_v2(string s) {		//8/5/2021		

	string result;

	//ascii method(with iteration)		runtime: 4ms,	memory: 6.4mb
	for (int i = 0; i < s.length(); i++) {
		if (i + 2 < s.length() && s[i + 2] == '#') {
			char alp = (s[i] - '0') * 10 + s[i + 1] - '0' + 96;
			i += 2;
			result += alp;
		}
		else {
			char alp = s[i] - '0' + 96;
			result += alp;
		}
	}

	//ascii method(without iteration)		runtime: 0ms,	memory: 6.1mb
	for (int i = 0; i < s.length();) {
		if (i + 2 < s.length() && s[i + 2] == '#') {
			char alp = (s[i] - '0') * 10 + s[i + 1] - '0' + 96;		//to get alphabet from an ascii
			i += 3;
			result += alp;
		}
		else {
			char alp = s[i++] - '0' + 96;
			result += alp;
		}
	}

	return result;
}

//Leetcode 746: Min Cost Climbing Stairs(Brute Force)		9/5/2021		O(n^2) Bad efficiency
int minCostClimbingStairs(vector<int>& cost, int currentNum = 0, int index = 0) {

	if (index == 0)
		auto it = cost.insert(cost.begin(), 0);

	if (index >= cost.size() - 2)
		return currentNum;
	else
		return currentNum + min(minCostClimbingStairs(cost, cost[index + 1], index + 1), minCostClimbingStairs(cost, cost[index + 2], index + 2));
}

//13/5/2021			runtime: 8ms,	memory: 13.8mb	O(N)
using VT = vector<int>;
int minCostClimbingStairs_v2(VT& A) {

	int N = A.size();
	VT dp(N);
	dp[0] = A[0];
	dp[1] = A[1];

	for (int i = 2; i < N; ++i)
		dp[i] = A[i] + min(dp[i - 1], dp[i - 2]);

	return min(dp[N - 1], dp[N - 2]);
}

//Leetcode 198: House Robber		13/5/21			runtme: 0ms, memory: 7.7mb	O(N)
int maxRob(VT& V) {

	int N = V.size();
	VT dp(N);

	if (N == 1)
		return V[0];
	else if (N == 2)
		return max(V[0], V[1]);

	dp[0] = V[0];
	dp[1] = V[1];
	dp[2] = V[2] + V[0];

	for (int i = 3; i < N; ++i)
		dp[i] = V[i] + max(dp[i - 2], dp[i - 3]);

	return max(dp[N - 1], dp[N - 2]);
}

//Leetcode 213: House Robber 2		13/5/21			runtime: 0ms, memory: 8mb	O(N)
int maxRob_2(VT V) {

	int N = V.size();
	VT dp_0(N), dp_1(N);

	if (N == 1)
		return V[0];
	else if (N == 2)
		return max(V[0], V[1]);

	//starting index 0
	dp_0[0] = V[0];
	dp_0[1] = V[1];
	dp_0[2] = V[2] + V[0];

	for (int i = 3; i < N - 1; ++i)
		dp_0[i] = V[i] + max(dp_0[i - 2], dp_0[i - 3]);


	//starting index 1
	dp_1[0] = 0;
	dp_1[1] = V[1];
	dp_1[2] = V[2];

	for (int i = 3; i < N; ++i)
		dp_1[i] = V[i] + max(dp_1[i - 2], dp_1[i - 3]);

	return max(max(dp_0[N - 2], dp_0[N - 3]), max(dp_1[N - 2], dp_1[N - 3]));
}

//Leetcode 322: Coin Change		14/5/21			runtime: 56ms,	memory: 14.4mb
int coinChange(vector<int>& coins, int amount) {

	vector<int> dp(amount + 1);

	dp[0] = 0;

	for (int i = 1; i <= amount; ++i) {

		int min = amount + 1;
		for (int n : coins) {
			if (i - n >= 0 && dp[i - n] < min) {
				min = dp[i - n] + 1;
			}
		}

		dp[i] = min;
	}

	return dp[amount];
}

//Leetcode 303: Range Sum Query - Immutable		17/5/21			runtime: 24ms,	memory: 17mb, runtime & memory complexity: O(n)
int sumRange(int left, int right) {
	vector<int> NumArray = { -2, 0, 3, -5, 2, -1 };
	vector<int> dp(NumArray.size());

	dp[0] = NumArray[0];

	for (int i = 1; i < NumArray.size(); i++)
		dp[i] = NumArray[i] + dp[i - 1];

	return dp[right] - dp[left - 1];
}

//Leetcode 1641: Count Sorted Vowel Strings			18/5/21		runtime: 0ms,	memory: 6.5mb, complexity: O(5n)
int countVowelStrings(int n) {

	vector<vector<int>> vowelMatrix;

	vowelMatrix.push_back({ 1,1,1,1,1 });
	//vector<vector<int>>dp(n + 1, vector<int>(6));			size customize solution for 2d vector


	for (int i = 1; i < n; i++) {
		vector<int> temp;

		//count from behind(add i-1,j-1 to get the answer)
		for (int j = 4; j >= 0; j--) {
			if (j == 4)
				temp.push_back(1);
			else
				temp.insert(temp.begin(), vowelMatrix[i - 1][j] + temp[0]);
		}

		//store the number of valid pair for next pair calculation
		vowelMatrix.push_back(temp);
	}

	return accumulate(vowelMatrix[n - 1].begin(), vowelMatrix[n - 1].end(), 0);
}

//Leetcode 279:	Perfect Squares		21/5/21			runtime: 75.51%,	memory: 46.60%,		complexity: O(n*sqrt(n))
int numSquares(int n) {

	vector<int> dp(n + 1);

	for (int i = 0; i <= n; i++) {
		if (i <= 3)
			dp[i] = i;
		else {
			int _min = n;

			for (int j = 1; j * j <= i; j++) {
				_min = min(dp[i - j * j] + 1, _min);
			}

			dp[i] = _min;
		}
	}

	return dp[n];
}

//Binary tree class
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//N-ary tree class		//2/6/2021
struct Node {
public:
	int val;
	vector<Node*> children;

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

//Leetcode 617: Merge Two Binary Trees		24/5/21
int travelTree(TreeNode* root) {		//24/5/21	(DFS)

	if (root) {
		travelTree(root->left);
		cout << root->val << endl;
		travelTree(root->right);
	}

	return 0;
}

TreeNode* mergeTree(TreeNode* root1, TreeNode* root2) {		//25/5/21		runtime: 93.84%, memory: 55.23%,	complexity: NP

	if (root1 && root2) {
		root1->val += root2->val;
		root1->left = mergeTree(root1->left, root2->left);
		root1->right = mergeTree(root1->right, root2->right);
		return root1;
	}
	else
		return root1 ? root1 : root2;

	return root1;
}

//Leetcode 897: Increasing Order Search Tree		//25/5/21		runtime: 4ms, memory: 8mb, complexity: dk how to calculate, maybe O(h)
TreeNode* increasingBST(TreeNode* root) {
	TreeNode* current = root;

	TreeNode* newRoot = NULL;

	stack<TreeNode*> s;

	while (current || !s.empty())
	{
		/* Reach the left most Node of the
		   curr Node */
		while (current)
		{
			/* place pointer to a tree node on
			   the stack before traversing
			  the node's left subtree */
			s.push(current);
			current = current->left;
		}

		/* Current must be NULL at this point */
		current = s.top();
		s.pop();

		if (newRoot) {
			TreeNode* temp = newRoot;
			while (temp->right != NULL) temp = temp->right;
			temp->right = new TreeNode(current->val);
		}
		else {
			newRoot = new TreeNode(current->val);
		}

		/* we have visited the node and its
		   left subtree.  Now, it's right
		   subtree's turn */
		current = current->right;

	} /* end of while */

	return newRoot;
}

//Leetcode 589: N-ary Tree Preorder Traversal		
vector<int> preorder(Node* root) {				//2/6/2021		runtime: 5.45%, memory: 73.25&,	complexity(time & space): O(n = number of nodes)

	//create a list to store result
	vector<int> result;

	if (root == NULL) return result;

	//create stack to store current node
	stack<Node*> s;
	s.push(root);

	while (!s.empty()) {
		Node* current = s.top();
		s.pop();
		//store node val to result
		result.push_back(current->val);

		//store current node children to stack in desc order(draw out the understand)
		for (int i = current->children.size() - 1; i >= 0; i--)
			s.push(current->children.at(i));
	}

	return result;
}

//Leetcode 590: N-ary Tree Postorder Traversal		4/6/2021		runtime: 79.36%, memory: 78.16%, complexity(time & space): O(n = number of nodes)
vector<int> postorder(Node* root) {

	stack<Node*> s;
	stack<Node*> parent;
	//vector to store result
	vector<int> result;

	if (root)
		s.push(root);

	while (!s.empty()) {
		Node* current = s.top();

		if (current->children.size() > 0) {
			//to avoid duplicate visit
			if (parent.size() > 0 && current == parent.top()) {
				//if visited all the children, store the parent
				parent.pop();
				s.pop();
				result.push_back(current->val);
			}
			else {
				//marked as visited
				parent.push(current);
				//push all children into the stack in desc order(LIFO)
				for (int i = current->children.size() - 1; i >= 0; i--)
					s.push(current->children[i]);
			}
		}
		else {
			result.push_back(current->val);
			s.pop();
		}
	}

	return result;
}

//Leetcode 700: Search in a Binary Search Tree			5/6/2021
TreeNode* searchBST(TreeNode* root, int val) {

	//Binary Tree method								runtime: 36.00%, memory: 92.49%, complexity: O(n=number of nodes)
	TreeNode* current = root;

	stack<TreeNode*> s;

	while (current || !s.empty())
	{
		/* Reach the left most Node of the
		   curr Node */
		while (current)
		{
			/* place pointer to a tree node on
			   the stack before traversing
			  the node's left subtree */
			s.push(current);
			current = current->left;
		}

		/* Current must be NULL at this point */
		current = s.top();
		if (current->val == val) return current;
		s.pop();

		/* we have visited the node and its
		   left subtree.  Now, it's right
		   subtree's turn */
		current = current->right;

	} /* end of while */

	return NULL;

	//BST method										runtime: 16.49%, memory: 19.92%, complexity: <= O(n=number of nodes)
	while (root && root->val != val) {
		if (root->val < val) {
			root = root->right;
		}
		else {
			root = root->left;
		}
	}

	return root;
}

//Leetcode 1022: Sum of Root To Leaf Binary Numbers		6/6/2021		runtime: 86.27%, memory: 70.48%, complexity: O(N)
int sumRootToLeaf(TreeNode* root, int sum = 0) {

	if (root == nullptr) return 0;
	sum = (sum << 1) + root->val;
	if (root->left == nullptr && root->right == nullptr)
		return sum;

	return sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum);
}

//Leetcode 559: Maximum Depth of N-ary Tree		7/6/2021		runtime: 62.99%, memory: 20.20%, time: O(n=count of nodes), space: O(h=max height)
int maxNum = 0;
int maxDepth(Node* root, int current = 0) {
	if (root == nullptr) return current;
	if (++current > maxNum) maxNum = current;
	for (int i = 0; i < root->children.size(); i++) {
		maxDepth(root->children[i], current);
	}

	return maxNum;

	//Leetcode god solution
	if (!root) return 0;
	int depth = 1;
	for (auto child : root->children)
		depth = max(depth, maxDepth(child));

	return depth;
}

//Leetcode 104: Maximum Depth of Binary Tree		8/6/2021		runtime: 29.84%, memory: 12.23%, time: O(n=number of nodes), space: O(h=max height)
int maxDepth(TreeNode* root, int depth = 0) {
	if (root == nullptr) return depth;
	depth++;

	return max(maxDepth(root->right, depth), maxDepth(root->left, depth));
}
//Leetcode god solution
int maxDepth2(TreeNode* root) {
	return root ? max(maxDepth2(root->right), maxDepth2(root->left)) + 1 : 0;
}

//Leetcode 111: Minimum Depth of Binary Tree		9/6/2021		time&space: O(n=number of nodes)
int minDepth(TreeNode* root, int depth = 0) {
	if (!root) return depth;
	depth++;
	if (!root->left) return minDepth(root->right, depth);
	if (!root->right) return minDepth(root->left, depth);
	return min(minDepth(root->right, depth), minDepth(root->left, depth));
}

//Leetcode 965: Univalued Binary Tree			10/6/2021		time&space: O(n=number of nodes)
bool isUnivalTree(TreeNode* root) {
	if (!root) return true;
	if (root->left && root->left->val != root->val) return false;
	if (root->right && root->right->val != root->val) return false;
	return isUnivalTree(root->right) && isUnivalTree(root->left);
}

//Leetcode 226: Invert Binary Tree			11/6/2021			
/*Time complexity: O(n) where n is the number of nodes, and each nodes will sure be visited one time
Space complexity: O(h) where h is the height of the tree, O(h) function calls will be placed on the memory stack during recursion*/
TreeNode* invertBinaryTree(TreeNode* root) {
	if (root == nullptr) return root;
	TreeNode* tempRoot = root->right;
	root->right = root->left;
	root->left = tempRoot;
	invertBinaryTree(root->right);
	invertBinaryTree(root->left);
	return root;
}

//Leetcode 94: Binary Tree Inorder Traversal		11/6/2021
/*Time complexity will be O(n) which n denotes the counts of node od this tree.
Space complexity will be O(h) since we need h calls for reaching leaves h denotes to path length of the longest path in this tree. Or you can say O(logN) because h is bonded by  logN.*/
vector<int> store;
vector<int> inorderTraversal(TreeNode* root) {
	if (!root) return {};
	inorderTraversal(root->left);
	store.push_back(root->val);
	inorderTraversal(root->right);
	return store;
}

//Leetcode 637: Average Levels in Binary Tree		12/6/2021		time: O(n), space: O(n)
vector<double> averageOfLevels(TreeNode* root) {		//BFS traversal

	//To store result
	vector<double> res;
	//For BFS iteration
	queue<TreeNode*> q;
	if (root) q.push(root);

	while (!q.empty()) {
		long current_level_total_values = 0;           //long to prevent integer overflow
		int current_level_total_count = q.size();
		for (int i = 0; i < current_level_total_count; i++) {
			TreeNode* current = q.front();
			current_level_total_values += current->val;     //sum the value of nodes in same level
			q.pop();
			if (current->left) q.push(current->left);
			if (current->right) q.push(current->right);
		}
		res.push_back((double)current_level_total_values / current_level_total_count);    //store the average nodes values in same level, in decimal
	}

	return res;
}
//Leetcode 429: N-ary Tree Level Order Traversal		13/6/2021		time: O(n), space: O(n)
vector<vector<int>> levelOrder(Node* root) {

	vector<vector<int>> res;
	queue<Node*> q;

	if (root) q.push(root);

	while (!q.empty()) {
		vector<int> temp = {};              //clear temp vector to store new current node values
		int size = q.size();
		for (int i = 0; i < size; i++) {      //size = node count in current level
			Node* current = q.front();
			q.pop();                        //remove current level nodes from queue to keep track level
			temp.push_back(current->val);   //store all current level node val in temp
			for (Node* child : current->children) q.push(child);  //store every children of current node into the queue
		}
		res.push_back(temp);            //store temp in result
	}

	return res;
}

//Leetcode 98: Validate Binary Search Tree		14/6/2021	time&space: O(n=count of nodes)
vector<int> v;
bool isValidBST(TreeNode* root) {
	if (!root) return true;
	bool left = isValidBST(root->left);
	v.push_back(root->val);
	if (v.size() >= 2 && v.back() <= v[v.size() - 2]) return false;
	bool right = isValidBST(root->right);
	return left && right;
}

//Leetcode 107: Binary Tree Level Order Traversal II		14/6/2021		time&space: O(n=count of nodes)
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> res;
	queue<TreeNode*> q;
	if (root) q.push(root);
	while (!q.empty()) {
		vector<int> temp = {};
		int size = q.size();
		for (int i = 0; i < size; i++) {
			TreeNode* current = q.front();
			temp.push_back(current->val);
			q.pop();
			if (current->left) q.push(current->left);
			if (current->right) q.push(current->right);
		}
		res.insert(res.begin(), temp);    //just reverse insert into result vector, nothing special actually
	}

	return res;
}

//Leetcode 872: Leaf Similar Trees		15/6/2021		time&space: O(n1+n2)
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

//After thinking, with better recursive solution		15/6/2021		time&space: O(n1+n2)
void getLeaf(TreeNode* root, vector<int>& v) {
	if (!root) return;
	if (!root->left && !root->right) v.push_back(root->val);
	getLeaf(root->left, v);
	getLeaf(root->right, v);
}

bool leafSimilar2(TreeNode* root1, TreeNode* root2) {
	vector<int> v1, v2;
	getLeaf(root1, v1);
	getLeaf(root2, v2);

	return v1 == v2;
}

//Leetcode 145: Binary Tree PostOrder Traversal		16/6/2021		time: O(n), space: O(h)
vector<int> res;
vector<int> postorderTraversal(TreeNode* root) {
	if (!root) return {};
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	res.push_back(root->val);
	return res;
}

//Letcode 144: Binary Tree Preorder Traversal		16/6/2021		time: O(n), space: O(h)
vector<int> preorderTraversal(TreeNode* root) {
	if (!root) return {};
	res.push_back(root->val);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
	return res;
}

//Leetcode 653: Two Sum - Input is a BST		17/6/2021		time: O(2n), space: O(n)
bool existedVector(vector<int>& v, int num) {
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] == num) return true;
	}
	return false;
}

vector<int> twoSumIV;
bool findTarget(TreeNode* root, int k) {
	if (!root) return false;
	twoSumIV.push_back(root->val);
	if (existedVector(twoSumIV, k - root->val)) return true;
	return findTarget(root->left, k) || findTarget(root->right, k);
}

//Leetcode 606: Construct String from Binary Tree		19/6/2021	time: O(n), space: O(h)
string stringRes = "";
string tree2str(TreeNode* root, int level = 0) {
	if (!root) return "";
	level++;
	if (level == 1) {
		stringRes += to_string(root->val);
		if (!root->left && root->right) stringRes += "()";
		tree2str(root->left, level);
		tree2str(root->right, level);
	}
	else {
		stringRes += '(' + to_string(root->val);
		if (!root->left && root->right) stringRes += "()";
		tree2str(root->left, level);
		tree2str(root->right, level);
		stringRes += ')';
	}
	return stringRes;
}

//Leetcode 530: Minimum Absolute Difference in BST		20/6/2021		time: O(2n), space: O(h+n)
//(same solution)Leetcode 783: Minimum Distance Between BST Nodes		23/6/2021		time: O(2n), space: O(h+n)
int minNum = INT_MAX;
vector<int> findMinNum;
void getMinNum(int rootVal) {
	for (int n : findMinNum) {
		if (n > rootVal && n - rootVal < minNum) minNum = n - rootVal;
		else if (n < rootVal && rootVal - n < minNum) minNum = rootVal - n;
	}
	findMinNum.push_back(rootVal);
}

int getMinimumDifference(TreeNode* root) {
	if (!root) return 0;
	getMinimumDifference(root->left);
	getMinimumDifference(root->right);
	getMinNum(root->val);
	return minNum;
}

//Leetcode 100: Same Tree		23/6/2021	time:O(n), space: O(h)		//travel 2 tree
bool isSameTree(TreeNode* p, TreeNode* q) {
	//both is null
	if (!p && !q) return true;
	//only one is null
	else if (!p || !q) return false;
	//both not null, but not same value
	else if (p->val != q->val) return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//Leetcode 235: Lowest Common Ancestor of a Binary Search Tree		24/6/2021			time&space:O(n^2)
//bfs to find if the 2 nodes exist
bool isLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	queue<TreeNode*> que;
	que.push(root);

	bool existP = false;
	bool existQ = false;

	//if this root consist of this two nodes no matter in which position, return true
	while (!que.empty()) {
		TreeNode* current = que.front();
		que.pop();
		if (current == p) existP = true;
		if (current == q) existQ = true;
		if (current->left) que.push(current->left);
		if (current->right) que.push(current->right);
	}

	return existP && existQ;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	queue<TreeNode*> que;
	que.push(root);
	stack<TreeNode*> s;

	//bfs to store nodes in queue in ascending, then store in stack in descending order(find ansestor from bottom)
	while (!que.empty()) {
		TreeNode* current = que.front();
		que.pop();
		s.push(current);
		if (current->left) que.push(current->left);
		if (current->right) que.push(current->right);
	}

	//traversal in stack to find the ancestor
	while (!s.empty()) {
		TreeNode* current = s.top();
		s.pop();
		if (isLowestCommonAncestor(current, p, q)) return current;
	}

	return NULL;
}

//No need to do as above if the it is BST, new solution
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
	//if root val larger than both, go right
	if (root->val > p->val && root->val > q->val)
		return lowestCommonAncestor2(root->left, p, q);
	//if root val smaller than both, go left
	else if (root->val < p->val && root->val < q->val)
		return lowestCommonAncestor(root->right, p, q);
	//if root val between them, this is the lowest common ancestor
	return root;
}

//Leetcode 404: Sum of Left Leaves		27/6/2021		time: O(n), space: O(n)
int sumOfLeftLeaves(TreeNode* root) {
	//Prepare a queue for bfs traversal
	queue<TreeNode*> q;
	q.push(root);

	//declare initial sum of root value
	int sum = 0;

	while (!q.empty()) {
		TreeNode* current = q.front();
		q.pop();
		//Only do things on left node
		if (current->left) {
			//if left node is a leaf(no children), sum it up
			//If it is a leaf node, no need to queue up anymore
			if (!current->left->left && !current->left->right)
				sum += current->left->val;
			else
				q.push(current->left);
		}
		if (current->right) q.push(current->right);
	}

	return sum;
}

//Leetcode 993: Cousins in Binary Tree			28/6/2021		time&space: O(n), vector and stack	
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
				//they are siblings, return false
				if ((current->left->val == x && current->right->val == y) || (current->left->val == y && current->right->val == x))
					return false;

			if (current->left) q.push(current->left);
			if (current->right) q.push(current->right);
		}

		if (isX && isY) return true;
	}

	return false;
}

//Leetcode 543: Diameter of Binary Tree		30/6/2021		time&space: O(n^2)
int maxSideDepth(TreeNode* root, int depth = 0) {
	if (root == nullptr) return depth;
	depth++;

	return max(maxSideDepth(root->right, depth), maxSideDepth(root->left, depth));
}

int diameterOfSingleNode(TreeNode* root) {
	return maxSideDepth(root->left) + maxSideDepth(root->right);
}

int maxDiameter = 0;
int diameterOfBinaryTree(TreeNode* root) {
	if (!root) return maxDiameter;
	maxDiameter = max(maxDiameter, diameterOfSingleNode(root));
	diameterOfBinaryTree(root->left);
	diameterOfBinaryTree(root->right);
	return maxDiameter;
}

//Leetcode 101: Symmetric Tree		1/7/2021		time: O(n), space: O(h)
TreeNode* invertTree(TreeNode* root) {
	if (!root) return root;
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

bool isSymmetric(TreeNode* root) {
	return isSameTree(root->left, invertTree(root->right));
}

//Leetcode 572: Subtree of Another Tree			1/7/2021		time: O(n), space: O(h)
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	if (!root) return false;
	if (isSameTree(root, subRoot)) return true;
	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

//Leetcode 112: Path Sum		3/7/2021			time: O(n), space: O(h)
bool hasPathSum(TreeNode* root, int targetSum, int sum = 0) {
	if (!root) return false;
	sum += root->val;
	//reached at leaf node
	if (!root->left && !root->right)
		return sum == targetSum;
	return hasPathSum(root->left, targetSum, sum) || hasPathSum(root->right, targetSum, sum);
}

//Leetcode 671: Second Minimum Node In Binary Tree		3/7/2021		time:O(n), space:O(h)
void storeNode(TreeNode* root, vector<int>& vec) {
	if (!root) return;
	vec.push_back(root->val);
	storeNode(root->left, vec);
	storeNode(root->right, vec);
	return;
}

int findSecondMinimumValue(TreeNode* root) {
	vector<int> vec;
	storeNode(root, vec);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	return vec.size() > 1 ? vec[1] : -1;
}

int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	//Binary Tree
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(19);
	root->left->left->left = new TreeNode(15);
	root->left->left->right = new TreeNode(8);
	root->left->left->left->right = new TreeNode(17);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(10);
	root->right->left->left = new TreeNode(13);
	root->right->left->right = new TreeNode(14);
	root->right->left->right->left = new TreeNode(18);
	root->right->right = new TreeNode(5);
	root->right->right->right = new TreeNode(6);
	root->right->right->right->left = new TreeNode(7);
	root->right->right->right->left->right = new TreeNode(9);
	root->right->right->right->right = new TreeNode(11);
	root->right->right->right->right->right = new TreeNode(12);
	root->right->right->right->right->left = new TreeNode(16);
	root->right->right->right->right->left->left = new TreeNode(20);


	//N-ary Tree
	/*Node* root = new Node(1, { new Node(3) , new Node(2) , new Node(4) });
	root->children.at(0) = new Node(3, { new Node(5) , new Node(6) });*/
	
	cout << isCousins(root,11,17);

	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
