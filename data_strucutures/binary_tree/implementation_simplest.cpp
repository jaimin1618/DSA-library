#include<bits/stdc++.h>
using namespace std;

// Structure definition for a node in a binary tree
struct Node {
    // Defining the value of the node (integer data)
    int data;        

    // Reference pointer to the left child node
    Node* left;      
    // Reference pointer to the right child node
    Node* right;      

    // Method to initialize the node with a value
    Node(int val) {
        // Set the value of the
        // node to the passed integer
        data = val;   
        // Initialize left and 
        //r ight pointers as NULL
        left = right = nullptr;  
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->right = new Node(5);

	/*
	   1
	  / \
     2   3
      \
       5
    */
	return 0;
}