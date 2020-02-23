#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int majorityElement(vector<int> &nums) {
	int max;
	int count = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		if (count == 0) {
			max = nums[i];
			count = 1;
		} else if (max != nums[i]) {
			count --;
		} else {
			count ++;
		}
	}

	return max;
}

int main()
{
	int a[3] = {6, 5, 5};
	vector<int> abc(a, a + 3);

	cout << majorityElement(abc);
	return 0;
}
