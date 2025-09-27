#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
	Node(int v, Node *l, Node *r): val(v), left(l), right(r) {};
};

void bfs(Node *root) {
	queue<Node *> q;
	q.push(root);

	while(!q.empty()) {
		Node *f = q.front();
		q.pop();

		cout << f->val << endl;

		if(f->left != nullptr)
			q.push(f->left);
		if(f->right != nullptr)
			q.push(f->right);
	}
}

// BFS level by traversal
void bfs_level_traversal(Node *root) {
	queue<Node *> q;
	q.push(root);
	int level = 0;

	while(!q.empty()) {
		int size = q.size();

		cout << "At level " << level << ": ";
		for(int i = 0; i < size; ++i) {
			Node *f = q.front();
			q.pop();

			// process current node
			cout << f->val << " ";

			if(f->left != nullptr)
				q.push(f->left);
			if(f->right != nullptr)
				q.push(f->right);
		}
		cout << endl;

		level++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Node *root = new Node(3);
	root->left = new Node(9);
	root->right = new Node(20);
	root->right->left = new Node(15);
	root->right->right = new Node(7);

	bfs(root);
	bfs_level_traversal(root);

	return 0;
}