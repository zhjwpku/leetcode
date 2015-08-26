#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &nums) {
	int check = 0;
	for (int i = 0; i < nums.size(); i++ ) {
		check ^= nums[i] ^ (i + 1);
	}

	return check;
}

int main() {
	int a[10] = {0, 2, 7, 6, 5, 4, 1, 8, 9};
	vector<int> b(a, a+9);
	cout << missingNumber(b) << endl;
	return 0;
}
