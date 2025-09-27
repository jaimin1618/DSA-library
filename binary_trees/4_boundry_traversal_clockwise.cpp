#include<bits/stdc++.h>
using namespace std;
// iterative solution

struct Node {
	int val;
	Node *left, *right;
	Node (int v): val(v), left(nullptr), right(nullptr) {};
	Node (int v, Node *l, Node *r): val(v), left(l), right(r) {};
};

// Steps for the solution. 
// No understanding it's standard question you will have to observe for such ideas. 
// 3. right boundry traversal, excluding leaf nodes
//    right boundry means: Go right, rigth, right and if there doesn't exist right to left. 
//    And finally reverse the items found during traversal for anti-clockwise border printing.
// 1. left boundry traversal, excluding leaf nodes. 
// 	  left boundry means: Go left, left, left, and if there doesn't exist left go to right -
// 2. traverse leaf nodes
//    leaf nodes means: Normal inorder traversal with node->left == null && node->right == null 

bool leaf(Node *root) {
	if(root->left == nullptr && root->right == nullptr)
		return true;
	return false;
}

vector<int> right_boundry(Node *root) {
	if(root == nullptr)
		return {};

	Node *curr = root->right;
	vector<int> right_nodes;

	while(curr != nullptr) {
		if(!leaf(curr)) {
			right_nodes.push_back(curr->val);
		}

		if(curr->right != nullptr)
			curr = curr->right;
		else
			curr = curr->left;
	}

	return right_nodes;
}

vector<int> left_boundry_reversed(Node *root) {
	if(root == nullptr)
		return {};

	Node *curr = root->left;
	vector<int> left_nodes;

	while(curr != nullptr) {
		if(!leaf(curr)) {
			left_nodes.push_back(curr->val);
		}

		if(curr->left != nullptr)
			curr = curr->left;
		else
			curr = curr->right;
	}

	reverse(left_nodes.begin(), left_nodes.end());
	return left_nodes;
}

void leaf_boundry(Node *root, vector<int>& nodes) {
	if(root == nullptr)
		return;

	leaf_boundry(root->left, nodes);
	if(root->left == nullptr && root->right == nullptr)
		nodes.push_back(root->val);
	leaf_boundry(root->right, nodes);
}

void boundry_traversal_clockwise(Node *root) {
	if(root == nullptr)
		return;

	cout << root->val << " ";

	vector<int> right_nodes = right_boundry(root);

	for(auto& el: right_nodes)
		cout << el << " ";

	vector<int> leaf_nodes;
	leaf_boundry(root, leaf_nodes);
	reverse(leaf_nodes.begin(), leaf_nodes.end());
	for(auto& el: leaf_nodes)
		cout << el << " ";

	vector<int> left_nodes = left_boundry_reversed(root);
	for(auto& el: left_nodes)
		cout << el <<  " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(7);
	root->left->left = new Node(3);
	root->left->left->right = new Node(4);
	root->left->left->right->left = new Node(5);
	root->left->left->right->right = new Node(6);
	root->right->right = new Node(8);
	root->right->right->left = new Node(9);
	root->right->right->left->left = new Node(10);
	root->right->right->left->right = new Node(11);

	boundry_traversal_clockwise(root);

	// vector<int> t = right_boundry(root);
	// for(auto& el: t)
	// 	cout << el << " ";

	return 0;
}