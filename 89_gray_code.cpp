#include <iostream>
#include <vector>

using namespace std;

static unsigned int binary_to_gray(unsigned int n) {
	return n ^ (n >> 1);
}

vector<int> grayCode(int n) {
	vector<int >res;
	const size_t size = 1 << n;
	res.reserve(size);
	for (size_t i = 0; i < size; i++)
		res.push_back(binary_to_gray(i));

	return res;
}

int main()
{
	int n;
	vector<int> res;
	while (cin >> n) {
		res = grayCode(n);
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}

	return 0;
}
