#include <iostream>
#include <vector>
#include <list>
using namespace std;

class TrieNode {
public:
	//char val;
	int count;
	bool flag;
	TrieNode *child[26] = {NULL};
	TrieNode() {
		count = 0;
		flag = false;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode *p = root;
		for (char c : word) {
			if (p->child[c-'a'] == NULL) {
				TrieNode *q = new TrieNode();
				p->child[c-'a'] = q;
				p->count++;
				p = q;
			} else {
				p = p->child[c-'a'];
			}
		}

		p->flag = true;
	}

	bool search(string word) {
		TrieNode *p = root;
		for (char c : word) {
			if (p->child[c-'a'] == NULL)
				return false;
			else
				p = p->child[c-'a'];
		}

		return p->flag;
	}

	bool startsWith(string prefix) {
		TrieNode *p = root;
		for (char c : prefix) {
			if (p->child[c-'a'] == NULL)
				return false;
			else
				p = p->child[c-'a'];
		}

		return true;
	}

private:
	TrieNode *root;
};

int main() {
	Trie trie;
	trie.insert("a");
	cout << trie.search("a") << endl;
	return 0;
}
