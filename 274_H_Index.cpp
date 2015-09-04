#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int>& citations) {
	sort(citations.begin(), citations.end());
	int len = citations.size();

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] >= len - i)
			return len - i;
	}
}

int main()
{
	int A[] = {3, 0, 6, 1, 5};
	vector<int> citations(A, A+5);

	cout << hIndex(citations) << endl;

	return 0;
}
