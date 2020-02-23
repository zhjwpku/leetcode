bool search(vector<int> &nums, int target) {
	int l = 0;
	int r = nums.size() - 1;

	while (l < r - 1) {	// at least 3 element
		int m = (l+r)/2;
		if (nums[m] == target)
			return true;
		if (nums[l] < nums[m]) {//left part is ordered
			if (nums[l] <= target && target < nums[m])
				r = m - 1;
			else
				l = m + 1;
		} else if (nums[l] > nums[m]){	// right part is ordered
			if (nums[r] >= target && target > nums[m])
				l = m + 1;
			else
				r = m - 1;
		} else {
			l++;
		}
	}

	if (nums[l] == target || nums[r] == target)
		return true;
	return false;
}
