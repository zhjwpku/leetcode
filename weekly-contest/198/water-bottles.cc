#include <gtest/gtest.h>

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while (numBottles >= numExchange) {
            ans += numBottles / numExchange;
            numBottles = numBottles % numExchange + numBottles / numExchange;
        }

        return ans;
    }
};

TEST(numWaterBottles, test0)
{
    Solution s;
    EXPECT_EQ(s.numWaterBottles(2, 3), 2);
}