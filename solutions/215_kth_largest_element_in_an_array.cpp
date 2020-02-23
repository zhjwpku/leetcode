#include <iostream>
#include <vector>
using namespace std;

int find_kthLargest(vector<int> &nums, int l, int r, int k) {
	cout << "l: " << l << " r: " << r << " k: " << k << endl;
	int key = nums[l];
	int i = l;
	int j = r;
	while (i < j) {
		while (i < j && nums[j] >= key) j--;
			nums[i] = nums[j];
		while (i < j && nums[i] <= key) i++;
			nums[j] = nums[i];
	}
	nums[i] = key;

	for (int ii = 0; ii < nums.size(); ii++)
		cout << nums[ii] << " ";
	cout << endl;

	if (r - i + 1 == k)
		return nums[i];
	else if (r - k >= i)
		return find_kthLargest(nums, i+1, r, k);
	else
		return find_kthLargest(nums, l, i-1, k-(r-i+1));
}

int main()
{
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(0);
	cout << find_kthLargest(nums, 0, nums.size() - 1, 4) << endl;
}
