#include <iostream>
#include <string>

using namespace std;

int minDistance(string word1, string word2) {
	int n = word2.size();

	vector<int> vec1(n+1, 0);
	vector<int> vec2(n+1, 0);

	for (int i = 0; i <= n; i++)
		vec1[i] = i;

	for (int i = 0; i < word1.size(); i++) {
		vec2[0] = i + 1;
		for (int j = 1; j <= n; j++) {
			if (word1[i] == word2[j-1]) {
				vec2[j] = vec1[j-1];
			} else
				vec2[j] = min(min(vec1[j], vec2[j-1]), vec1[j-1]) + 1;
		}

		swap(vec1, vec2);
	}

	return vec1[n];
}
