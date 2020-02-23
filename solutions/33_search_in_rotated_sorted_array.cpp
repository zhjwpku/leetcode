int search(vector<int> &nums, int target) {
	int l = 0;
	int r = nums.size() - 1;

	while (l < r - 1) {	// at least 3 element
		int m = (l+r)/2;
		if (nums[m] == target)
			return m;
		if (nums[l] < nums[m]) {//left part is ordered
			if (nums[l] <= target && target < nums[m])
				r = m - 1;
			else
				l = m + 1;
		} else {	// right part is ordered
			if (nums[r] >= target && target > nums[m])
				l = m + 1;
			else
				r = m - 1;
		}
	}

	if (nums[l] == target)
		return l;
	if (nums[r] == target)
		return r;
	return -1;
}
