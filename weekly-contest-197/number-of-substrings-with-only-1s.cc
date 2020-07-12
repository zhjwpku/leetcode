#include <string>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numSub(string s) {
        long cnt = 0;
        long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                ans += ((cnt + 1) * cnt) >> 1;
                ans %= 1000000007;
                cnt = 0;
            } else {
                cnt ++;
            }
        }

        ans += ((cnt + 1) * cnt) >> 1;
        ans %= 1000000007;
        return ans;
    }
};

TEST(numSub, test1) {
    Solution s;
    string str = "111111";
    EXPECT_EQ(s.numSub(str), 21);
}