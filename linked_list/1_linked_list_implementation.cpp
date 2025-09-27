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

// insert node at tail
Node* insertAtTail(Node* head, int k) {
    // Create a new node with data 'k'
    Node* newNode = new Node(k);

    if (head == nullptr) {
        return newNode;
    }

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->back = tail;

    return head;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	return 0;
}