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
