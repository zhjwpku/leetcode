#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
	int c0 = 0, c1 = 0, c2=0;
	for (int i = 0; i < nums.size(); i++) {
		switch (nums[i]) {
		case 0:
			c0++;
			break;
		case 1:
			c1++;
			break;
		case 2:
			c2++;
			break;
		}
	}

	for (int i = 0; i < nums.size(); i++) {
		if (i < c0)
			nums[i] = 0;
		else if (i < c0 + c1)
			nums[i] = 1;
		else
			nums[i] = 2;
	}
}

int main() {
	return 0;
}
