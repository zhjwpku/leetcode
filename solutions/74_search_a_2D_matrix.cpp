#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> >&matrix, int target) {
	if (matrix.size() == 0) return false;
	if (matrix[0].size() == 0) return false;
	int m = matrix.size();
	int n = matrix[0].size();

	int l = 0;
	int r = m * n - 1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (matrix[mid/n][mid%n] == target)
			return true;
		else if (matrix[mid/n][mid%n] > target)
			r = mid - 1;
		else
			l = mid + 1;
	}

	return false;
}
