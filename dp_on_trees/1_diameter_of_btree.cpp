#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* left = nullptr;
	Node* right = nullptr;
};

int solve(Node *root, int& result) {
	if(root == nullptr)
		return 0;

	int lh = solve(root->left, result);
	int rh = solve(root->right, result);

	// calculate height on current node to pass it to parent node as result
	int temp = 1 + max(lh, rh);

	// compare path passing from root (or current node) and longest path that will be passed to parent
	int ans = max(temp, 1 + lh + rh);

	// update answer if current answer is best answer
	result = max(result, ans);

	// pass current (temporary result) to parent node
	return temp;
}

int diameter(Node *root) {
	int result = INT_MIN;
	solve(root, result);
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Node* root = new Node();
	root->left = new Node();
	root->left->left = new Node();
	root->left->right = new Node();
	root->right = new Node();

	cout << diameter(root) << '\n';





	
	return 0;
}