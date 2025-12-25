#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

void inorder(Node *root) {
	if(root == nullptr)
		return;


	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}

void preorder(Node *root) {
	if(root == nullptr)
		return;

	cout << root->data << endl;
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node *root) {
	if(root == nullptr)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	

	return 0;
}