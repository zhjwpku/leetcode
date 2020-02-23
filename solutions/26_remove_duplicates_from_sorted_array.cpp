int removeDuplicates(vector<int> &num) {
	if (num.size() <= 1)
		return num.size();

	int index = 0;
	for (int i = 1; i < num.size(); i++) {
		if (num[i] != num[index])
			num[++index] = num[i];
	}

	return index+1;
}
