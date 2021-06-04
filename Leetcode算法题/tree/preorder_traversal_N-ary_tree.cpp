//https://leetcode.com/problems/n-ary-tree-preorder-traversal/
//https://www.youtube.com/watch?v=DAIN1ZzvFeA&t=168s

//Leetcode 589: N-ary Tree Preorder Traversal		2/6/2021		runtime: 5.45%, memory: 73.25&,	complexity: O(n)
class Node {
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

vector<int> preorder(Node* root) {			

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

int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	Node* root = new Node(1, { new Node(3) , new Node(2) , new Node(4) });
	root->children.at(0) = new Node(3, { new Node(5) , new Node(6) });

	for (int n : preorder(root)) {
		cout << n << endl;
	}

	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
