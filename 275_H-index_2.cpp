int hIndex(vector<int>& citations) {
	int len = citations.size();

	if (len == 0) return 0;

	int l = 0;
	int r = len - 1;

	while (l < r) {
		int i = (l+r)/2;
		if (citations[i] >= len - i)
			r = i;
		else
			l = i + 1;
	}

	if (citations[l] >= len - l)
		return len - l;
	else
		return len - l - 1;
}
