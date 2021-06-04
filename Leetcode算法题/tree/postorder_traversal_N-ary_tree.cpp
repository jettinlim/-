//https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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

//Leetcode 590: N-ary Tree Postorder Traversal		4/6/2021    runtime: 79.36%, memory: 78.16%, complexity(time & space): O(n = number of nodes)
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

int main()
{
	auto t1 = chrono::high_resolution_clock::now();

	Node* root = new Node(1, { new Node(3) , new Node(2) , new Node(4) });
	root->children.at(0) = new Node(3, { new Node(5) , new Node(6) });


	for (int n : postorder(root)) {
		cout << n << endl;
	}

	auto t2 = chrono::high_resolution_clock::now();
	auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	cout << "\n\nRuntime: " << t3.count() << "ms\n";

	return 0;
}
