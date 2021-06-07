//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;

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

int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	//N-ary Tree
	Node* root = new Node(1, { new Node(3) , new Node(2) , new Node(4) });
	root->children.at(0) = new Node(3, { new Node(5) , new Node(6) });

	cout << maxDepth(root);

	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
