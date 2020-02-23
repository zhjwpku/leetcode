#include <iostream>
#include <unordered_map>
using namespace std;

vector<vector<string> > groupAnagrams(vector<string> &strs) {
	unordered_map<string, vector<string> > group;

	for (int i = 0; i < strs.size(); i++) {
		string key = strs[i];
		sort(key.begin(), key.end());

		group[key].push_back(strs[i]);
	}

	vector<vector<string> > result;

	for (auto m : group) {
		vector<string> anagram(m.second.begin(), m.second.end());
		sort(anagram.begin(), anagram.end());
		result.push_back(anagram);
	}

	return result;
}
