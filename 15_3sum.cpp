vector<vector<int>> threeSum(vector<int> &num) {
	vector<vector<int>> result;
	if (num.size() < 3)
		return result;

	sort(num.begin(), num.end());
	const int target = 0;

	for (int i = 0; i < num.size() - 2; i++) {
		int j = i + 1;
		int k = num.size() - 1;
		while (j < k) {
			if (num[i] + num[j] + num[k] < target)
				j++;
			else if (num[i] + num[j] + num[k] > target)
				k--;
			else {
				result.push_back({num[i], num[j], num[k]});
				j++;
				k--;
			}
		}
	}

	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}

/* using 2 sum */
vector<vector<int> > threeSum(vector<int> &nums) {
	vector<vector<int> > results;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++) {
		twoSum(i, nums, results, 0 - nums[i]);

		while (i < nums.size()-1 && nums[i] == nums[i+1])
			i++;
	}

	return results;
}

void twoSum(int index, vector<int> &nums, vector<vector<int> > &results, int sum) {
	unordered_map<int, int> record;

	for (int i = index + 1; i < nums.size(); i++) {
		if (record.find(nums[i]) == record.end())
			record[sum-nums[i]] = nums[i];
		else {
			vector<int> vec;
			vec.push_back(nums[index]);
			vec.push_back(record[nums[i]]);
			vec.push_back(nums[i]);

			results.push_back(vec);

			while (i < nums.size() - 1 && nums[i] == nums[i+1])
				i++;
		}
	}
}
