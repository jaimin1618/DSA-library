#include<bits/stdc++.h>
using namespace std;
// Solid question. Worth doing! 
// Important pattern question: will be used for binary tree views, top bottom left right.. and all

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>> q;
        q.push(make_tuple(root, 0, 0)); // <-- store NODE, Vertical, Level
        int level = 0;

        // important part! how do we keep or save traversed information. 
        // unordered_map won't work because we want to store vertical and level information in ordered manner
        // to easily iterate at last. 
        // we use multiset to keep nodes with similar data, and they are sorted in ascending order also.
        map<int, map<int, multiset<int>>> temp;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                tuple<TreeNode*, int, int> f = q.front();
                q.pop();

                TreeNode* curr = get<0>(f);
                cout << curr->val << " ";
                int vertical = get<1>(f);
                int level = get<2>(f);

                temp[vertical][level].insert(curr->val); 

                if (curr->left != nullptr) {
                	// when we push childs of tree - we update their verticals and level
                	//           0 (0,0)
                	//          / \
                	//   (-1,1)1   2(1,1)
                    q.push(make_tuple(curr->left, vertical - 1, level + 1));
                } 
                if (curr->right != nullptr) {
                    q.push(make_tuple(curr->right, vertical + 1, level + 1));
                }
            }

            level++;
        }

        vector<vector<int>> ans;

        for (auto& a : temp) {
            vector<int> row;
            for (auto& b : a.second) {
                row.insert(row.end(), b.second.begin(), b.second.end());
            }
            ans.push_back(row);
        }

        return ans;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	TreeNode *root;

	queue<tuple<TreeNode *, int, int>> q;
	q.push(make_tuple(root, 0, 0));
        

	return 0;
}