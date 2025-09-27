#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *prev;
	Node *next;
	Node(int data) {
		data = data;
		prev = nullptr;
		next = nullptr;
	}
	Node(int data, Node *prev, Node *next) {
		data = data;
		prev = prev;
		next = next;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v {1, 2, 3, 4, 5};
	Node *head = nullptr;

	for(auto& el: v) {
		Node = new Node(el);
	}


	return 0;
}