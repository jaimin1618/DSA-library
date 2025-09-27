#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node (int _data): data(_data), left(nullptr), right(nullptr) {};
	Node (int _data, Node *_left, Node *_right): data(_data), left(_left), right(_right) {};
};

void bfs(Node *root) {
	queue<Node *> q;
	q.push(root);

	cout << "Nodes: ";
	while(!q.empty()) {
		Node *f = q.front();
		q.pop();

		// process current node
		cout << f->data << " ";

		if(f->left != nullptr)
			q.push(f->left);
		if(f->right != nullptr)
			q.push(f->right);
	}
	cout << endl;
}

void createBinaryTree(vector<int>& v) {
	Node *root = nullptr;


	for(int i = 0; i < v.size(); ++i) {
		int currentNode = v[i];
		int leftNode = v[2 * i + 1];
		int rightNode = v[2 * i + 2];

		if(root == nullptr) {
			root = new Node(currentNode);

			if(leftNode != -1)
				root
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> nodes { 1, 2, 3, 4, 10, 9, 11, -1, 5, -1, -1, -1, -1, -1, -1, -1, 6 };

	return 0;
}