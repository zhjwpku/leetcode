#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> >&matrix, int x, int y, int target) {
	if (x >= matrix.size() || y < 0) return false;
	if (matrix[x][y] == target) return true;
	else if (matrix[x][y] < target) return searchMatrix(matrix, x + 1, y, target);
	else if (matrix[x][y] > target) return searchMatrix(matrix, x, y - 1, target);
}

bool searchMatrix(vector<vector<int> >& matrix, int target) {
	if (matrix.size() == 0) return false;
	return searchMatrix(matrix, 0, matrix[0].size() - 1, target);
}
