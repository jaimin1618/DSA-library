#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
	Node(int v, Node *l, Node *r): val(v), left(l), right(r) {};
};

// IT WAS EASY PEASY BRO!
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    queue<TreeNode *> q;

    if(root != nullptr)
        q.push(root);
    int level = 0;

    // need to keep track of level
    while(!q.empty()) {
        int size = q.size();
        vector<int> temp;

        for(int i = 0; i < size; ++i) {
            TreeNode *f = q.front();
            q.pop();

            temp.push_back(f->val);

            if(f->left != nullptr)
                q.push(f->left);
            if(f->right != nullptr)
                q.push(f->right);
        }

        if(level % 2 != 0) {
            reverse(temp.begin(), temp.end());
        }

        ans.push_back(temp);

        level++;
    }

    return ans;
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