int removeDuplicates(vector<int >& nums) {
	int index = 0;

	for (int i = 0; i < nums.size(); i++ ) {
		if (i > 0 && i < n-1 && nums[i] == nums[i-1] && nums[i] == nums[i+1])
			continue;

		nums[index++] = A[i];
	}

	return index;
}
