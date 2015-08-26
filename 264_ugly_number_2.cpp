#include <iostream>
#include <vector>
using namespace std;

int nthUglyNumber(int n) {
	if (n < 1)
		return 0;

	int id2 = 0, id3 = 0, id5 = 0;
	int res = 1;

	vector<int> buf;
	while (--n) {
		buf.push_back(res);

		int v2 = 2 * buf[id2];
		int v3 = 3 * buf[id3];
		int v5 = 5 * buf[id5];

		res = min(v2, min(v3, v5));
		id2 += (res == v2);
		id3 += (res == v3);
		id5 += (res == v5);
	}

	return res;
}

int main() {
	int n;
	while (cin >> n) {
		cout << nthUglyNumber(n) << endl;
	}

	return 0;
}
