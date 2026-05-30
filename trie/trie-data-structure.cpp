#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
	TrieNode* children[26];
	bool isEnd;

	TrieNode() {
		isEnd = false;
		for(int i = 0; i < 26; ++i) {
			children[i] = nullptr;
		}
	}
};

class Trie {
	TrieNode* root;

public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode *node = root;

		for(auto& c: word) {
			int ind = c - 'a';

			if(node->children[ind] == nullptr) {
				node->children[ind] = new TrieNode();
			}

			node = node->children[ind];
		}

		node->isEnd = true;
	}

	// searches full string - "jaimin"
	bool search(string word) {
		TrieNode *node = root;

		for(auto& c: word) {
			int ind = c - 'a';

			if(node->children[ind] == nullptr)
				return false;

			node = node->children[ind];
		}

		return node->isEnd;
	}

	bool startsWith(string word) {
		TrieNode *node = root;

		for(auto& c: word) {
			int ind = c - 'a';

			if(node->children[ind] == nullptr)
				return false;

			node = node->children[ind];
		}

		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Trie t;

	t.insert("cpp");
	t.insert("java");
	t.insert("javascript");
	t.insert("python");
	t.insert("csharp");


	cout << t.search("cpp") << endl;
	cout << t.search("java") << endl;
	cout << t.search("cpp") << endl;
	cout << t.startsWith("javat") << endl;


	return 0;
}