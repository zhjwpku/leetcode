#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int numSquares(int n) {
	int m = (int)sqrt(double(n));
	vector<int> dp(n+1, 0);
	vector<int> dp2(n+1, 0);
	//vector<vector<int> > dp(m, vector<int>(n+1, 0));

	for (int i = 1; i <=n; i++)
		dp[i] = i;

	for (int i = 1; i < m ; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < (i+1) * (i+1))
				dp2[j] = dp[j];
			else
				dp2[j] = min(dp2[j-(i+1)*(i+1)] + 1, dp[j]);
		}
		swap(dp, dp2);
	}

	return dp[n];
}

int main()
{
	int a;
	while (cin >> a)
		cout << numSquares(a) << endl;
	return 0;
}
