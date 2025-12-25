#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
	Node(int d): data(d), left(nullptr), right(nullptr) {};
};

bool rootToNodePath(Node *root, int node, vector<int>& path) {
	if(root == nullptr)
		return false;

	// add current node before checking if we are reached or not
	path.push_back(root->data);

	if(root->data == node)
		return true;

	// check left and right both
	bool l = rootToNodePath(root->left, node, path);
	bool r = rootToNodePath(root->right, node, path);

	if(l || r)
		return true;

	// backtrack - 
	path.pop_back();
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);

	vector<int> path;
	rootToNodePath(root, 50, path);

	cout << "path: ";
	for(auto& node: path)
		cout << node << " ";
	cout << endl;






	return 0;
}