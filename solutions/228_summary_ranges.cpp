#include <iostream>

vector<string> summaryRanges(vector<int> &nums) {
	vector<string> res;

	if (nums.size() == 0) return res;

	int begin = nums[0];
	int last = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == last + 1) {
			last ++;
		} else {
			stringstream ss;
			if (begin == last)
				ss << begin;
			else
				ss << begin << "->" << last;
			string tmp;
			ss >> tmp;
			res.push_back(tmp);
			begin = nums[i];
			last = nums[i];
		}
	}

	stringstream ss;
	if (begin == last)
		ss << begin;
	else
		ss << begin << "->" << last;
	string tmp;
	ss >> tmp;
	res.push_back(tmp);

	return res;
}
