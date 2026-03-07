#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

// The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};

class Solution {
    // Interesting problem
    // Solved using serialization - postorder 
    // Save serialized (string version) subtree in map
    // if same substree found again in map duplicate found. 
    
    unordered_set<string> s;// stores count of subtree. 
    bool found = false;
    
    public:
    int dupSub(Node *root) {
        s.clear();
        found = false;
        solve(root);
        return found;
    }
    
    string solve(Node *root) {
        if(root == nullptr)
            return "#";
        
        string l = solve(root->left);
        string r = solve(root->right);
        
        // current string (postorder version)
        string curr = to_string(root->data) + "," + l + "," + r;
        
        if(l != "#" || r != "#") {
            // condition to ignore leaf nodes - 
            if(s.find(curr) != s.end())
                found = true;
            s.insert(curr);
        }
        
        return curr; 
    }
};

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	

	return 0;
}