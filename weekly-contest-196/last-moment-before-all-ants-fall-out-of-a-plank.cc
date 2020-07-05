#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if (left.size() == 0 && right.size() == 0) {
            return 0;
        }

        int res = 0;
        for (auto l: left) {
            res = max(res, l - 0);
        }
        for (auto r: right) {
            res = max(res, n - r);
        }
        return res;
    }
};

TEST(getLastMoment, test1)
{
    Solution s;
    vector<int> left {4, 3};
    vector<int> right {0, 1};
    EXPECT_EQ(s.getLastMoment(4, left, right), 4);
}

TEST(getLastMoment, test2)
{
    Solution s;
    vector<int> left {};
    vector<int> right {0, 1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(s.getLastMoment(7, left, right), 7);
}

TEST(getLastMoment, test3)
{
    Solution s;
    vector<int> right {};
    vector<int> left {0, 1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(s.getLastMoment(7, left, right), 7);
}