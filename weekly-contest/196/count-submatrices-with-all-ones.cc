/*
 * Ref: https://www.geeksforgeeks.org/number-of-submatrices-with-all-1s/
 */

#include <vector>
#include <stack>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    void helper(vector<vector<int>> &dp, const vector<vector<int>> &mat) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = dp[0].size() - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    continue;
                }

                if (j != dp[0].size() - 1) {
                    dp[i][j] = dp[i][j+1] + mat[i][j];
                } else {
                    dp[i][j] = mat[i][j];
                }
            }
        }
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        if (mat.size() == 0) {
            return 0;
        }
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 0));

        helper(dp, mat);

        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                cout << dp[i][j] << '\t';
            }
            cout << endl;
        }

        int ans = 0;

        for (int j = 0; j < dp[0].size(); j++) {
            int i = dp.size() - 1;
            stack<pair<int, int>> q;

            int to_sum = 0;
            while (i >= 0) {
                int c = 0;
                while (q.size() != 0 && q.top().first > dp[i][j]) {
                    to_sum -= (q.top().second + 1) * (q.top().first - dp[i][j]);
                    c += q.top().second + 1;
                    q.pop();
                }

                to_sum += dp[i][j];
                ans += to_sum;
                q.push(make_pair(dp[i][j], c));
                i--;
            }
        }
        return ans;
    }
};

TEST(numSubmat, test1)
{
    Solution s;
    vector<vector<int>> mat {
        {0, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 1, 1, 0}
    };

    EXPECT_EQ(s.numSubmat(mat), 24);
}

TEST(numSubmat, test2)
{
    Solution s;
    vector<vector<int>> mat {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    EXPECT_EQ(s.numSubmat(mat), 36);
}