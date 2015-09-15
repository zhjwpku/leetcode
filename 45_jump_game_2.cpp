#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> & nums) {
	int step = 0;
	for (int l = 0, r = 0; r < nums.size() - 1; step++) {
		int rNew = 0;
		for (int i = l; i <= r; i++) rNew = max(rNew, i + nums[i]);
		l = r+1;
		r = rNew;
	}

	return step;
}
