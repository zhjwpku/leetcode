#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> > &matrix, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i; j++)
			swap(matrix[i][j], matrix[n-1-j][n-1-i]);

	for (int i = 0; i < n/2; i++)
		for (int j = 0; j < n; j++)
			swap(matrix[i][j], matrix[n-1-i][j]);
}

void print_matrix(vector<vector<int> > &matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int n;
	vector<vector<int> > matrix;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> A;
		for (int j = 0; j < n; j++)
			A.push_back(i*n+j);
		matrix.push_back(A);
	}

	print_matrix(matrix, n);
	rotate(matrix, n);
	print_matrix(matrix, n);

	return 0;
}
