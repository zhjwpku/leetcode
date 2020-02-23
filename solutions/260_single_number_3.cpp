#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumber(vector<int> &nums){
	int diff = 0;
	for (auto i : nums) {
		diff ^= i;
	}

	diff &= -diff;

	vector<int> res = {0, 0};

	for (int num : nums) {
		if ((num & diff) == 0)
			res[0] ^= num;
		else
			res[1] ^= num;
	}

	return res;
}
