#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    double helper(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        double v = helper(x, n/2);
        if (n % 2 == 0) {
            return v * v;
        } else {
            return v * v * x;
        }
    }
public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / helper(x, -n);
        } else {
            return helper(x, n);
        }
    }
};

TEST(pow, pow1) {
    Solution s;

    EXPECT_EQ(s.myPow(10, 2), 100);
}
