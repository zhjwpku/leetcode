#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

void addNextWords(string word, unordered_set<string> &wordList, queue<string>& toVisit) {
	wordList.erase(word);
	for (int p = 0; p < (int)word.length(); p++) {
		char letter = word[p];
		for (int k = 0; k < 26; k++) {
			word[p] = 'a' + k;
			if (wordList.find(word) != wordList.end()) {
				toVisit.push(word);
				wordList.erase(word);
			}
		}

		word[p] = letter;
	}
}

int ladderLength(string beginWord, string endWord, unorder_set<string> &wordList) {
	wordList.insert(endWord);
	queue<string> toVisit;
	addNextWords(beginWord, wordList, toVisit);

	int dist = 2;
	while (!toVisit.empty()) {
		int num = toVisit.size();
		for (int i = 0; i < num; i++) {
			string word = toVisit.front();
			toVisit.pop();
			if (word == endWord) return dist;
			addNextWords(word, wordList, toVisit);
		}

		dist++;
	}
}
