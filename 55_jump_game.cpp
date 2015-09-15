#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
	if (nums.size() <= 1) return true;
	int step = nums[0];
	for (int i = 1; i < nums.size() - 1 && step != 0; i++) {
		step--;
		step = max(step, nums[i]);
	}

	return step != 0;
}

int main() {
	return 0;
}
