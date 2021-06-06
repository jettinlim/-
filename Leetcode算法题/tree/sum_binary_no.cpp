//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
//https://www.youtube.com/watch?v=Wj4mLZ7XW0A&t=537s

#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>


using namespace std;

//Leetcode 1022: Sum of Root To Leaf Binary Numbers		6/6/2021		runtime: 86.27%, memory: 70.48%, complexity = O(N)
int sumRootToLeaf(TreeNode* root, int sum = 0) {

	if (root == nullptr) return 0;
	sum = (sum << 1) + root->val;
	if (root->left == nullptr && root->right == nullptr)
		return sum;

	return sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum);
}

int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	//Binary Tree
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(1);
	root->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(1);

	cout << sumRootToLeaf(root);

	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
