#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    void printMatrix(vector<vector<bool>> &dp) {
        for (auto& arr: dp) {
            for (auto va: arr) {
                cout << va << '\t';
            }
            cout << endl;
        }
    }
public:
    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            if (p[i-1] == '*') {
                dp[i][0] = true;
            } else {
                break;
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[i-1] == '?' || p[i-1] == s[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[i-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        // printMatrix(dp);

        return dp[m][n];
    }
};

TEST(isMatch, testtrue) {
    Solution sol;
    string s = "adceb";
    string p = "*a*b";
    EXPECT_TRUE(sol.isMatch(s, p));
}

TEST(isMatch, testfalse) {
    Solution sol;
    string s = "mississippi";
    string p = "m??*ss*?i*pi";
    EXPECT_FALSE(sol.isMatch(s, p));
}

bool isMatch(string s, string p) {
    int slen = s.size(), plen = p.size();
    int i, j, iStar = -1, jStar = -1;

    for (i = 0, j = 0; i < slen; ++i, ++j) {
        if (p[j] == '*') {
            iStar = i;
            jStar = j;
            --i;
        } else {
            if (p[j] != s[i] && p[j] != '?') {
                if (iStar >= 0) {
                    i = iStar++;
                    j = jStar;
                } else
                    return false;
            }
        }
    }

    while (p[j] == '*') j++;

    return j == plen;
}
