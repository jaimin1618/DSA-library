#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node (int v): val(v), left(nullptr), right(nullptr) {};
	Node (int v, Node *l, Node *r): val(v), left(l), right(r) {};
};

// Steps for the solution. 
// No understanding it's standard question you will have to observe for such ideas. 
// 1. left boundry traversal, excluding leaf nodes
// 	  left boundry means: Go left, left, left, and if there doesn't exist left go to right. 
// 2. traverse leaf nodes
//    leaf nodes means: Normal inorder traversal with node->left == null && node->right == null. 
// 3. right boundry traversal, excluding leaf nodes, in reverse manner. 
//    right boundry means: Go right, rigth, right and if there doesn't exist right to left. 
//    And finally reverse the items found during traversal for anti-clockwise border printing. 

void left_boundry_traversal(Node *root, vector<int>& left_nodes) {
	if(root == nullptr)
		return;
	if(root->left == nullptr && root->right == nullptr)
		return;

	left_nodes.push_back(root->val);

	if(root->left != nullptr) {
		left_boundry_traversal(root->left, left_nodes);
	} else {
		left_boundry_traversal(root->right, left_nodes);
	}
}

void right_boundry_traversal(Node *root, vector<int>& right_nodes) {
	if(root == nullptr)
		return;
	if(root->left == nullptr && root->right == nullptr)
		return;

	right_nodes.push_back(root->val);

	if(root->right != nullptr) {
		right_boundry_traversal(root->right, right_nodes);
	} else {
		right_boundry_traversal(root->left, right_nodes);
	}
}

void leaf_traversal(Node *root, vector<int>& leaf_nodes) {
	if(root == nullptr)
		return;

	leaf_traversal(root->left, leaf_nodes);

	if(root->left == nullptr && root->right == nullptr) {
		// leaf node condition, with inorder
		leaf_nodes.push_back(root->val);
	}	

	leaf_traversal(root->right, leaf_nodes);
}

void inorder(Node *root) {
	if(root == nullptr)
		return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

vector<int> boundry_traversal_anti_clockwise(Node *root) {
	vector<int> ans;
	ans.push_back(root->val);

	vector<int> left_nodes, right_nodes, leaf_nodes; // maintain order in processing

	left_boundry_traversal(root->left, left_nodes);
	leaf_traversal(root, leaf_nodes);
	right_boundry_traversal(root->right, right_nodes);
	reverse(right_nodes.begin(), right_nodes.end());

	for(auto& el: left_nodes)
		ans.push_back(el);
	for(auto& el: leaf_nodes)
		ans.push_back(el);
	for(auto& el: right_nodes)
		ans.push_back(el);

	return ans;
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

	vector<int> anti_clockwise_boundry = boundry_traversal_anti_clockwise(root);

	cout << "Anti clockwise boundry of binary tree: ";
	for(auto& el: anti_clockwise_boundry)
		cout << el << " ";
	cout << endl;

	return 0;
};