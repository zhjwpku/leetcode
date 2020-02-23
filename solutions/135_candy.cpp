#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int> & ratings) {
	const int n = ratings.size();
	vector<int> increment(n);

	int inc = 1;

	for (int i = 1; i < n; i++) {
		if (ratings[i] > ratings[i-1]) {
			increament[i] = inc++;
		} else {
			inc = 1;
		}
	}

	inc = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (ratings[i] > ratings[i+1]) {
			increament[i] = max(increament[i], inc++);
		} else {
			inc = 1;
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		res += increament[i];

	return res + n;
}
