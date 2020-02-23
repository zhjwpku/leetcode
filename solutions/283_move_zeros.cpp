#include <iostream>
#include <vector>
using namespace std;

void moveZeros(vector<int>& nums) {
	int index = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			nums[index++] = nums[i];
		}
	}

	for (int i = index; i < nums.size(); i++) {
		nums[i] = 0;
	}
}

int main()
{
	int a[] = {0, 1, 0, 3, 12};
	vector<int> nums(a, a+5);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << "\t";
	cout << endl;

	moveZeros(nums);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << "\t";
	cout << endl;
	return 0;
}
