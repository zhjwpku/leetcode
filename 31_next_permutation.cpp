#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums) {
	//next_permutation(nums.begin(), nums.end()); // this is a library function
	int i = nums.size() - 1, k = i;
	while (i > 0 && nums[i-1] >= nums[i])
		i--;
	for (int j = i; j < k;  j++, k--)
		swap(nums[j], nums[k]);

	if (i > 0) {
		k = i--;
		while (nums[k] <= nums[i])
			k++;
		swap(nums[i], nums[k]);
	}
}

int main()
{

}
