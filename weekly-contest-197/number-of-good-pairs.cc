#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    ans ++;
                }
            }
        }

        return ans;
    }
};


TEST(numIdenticalPairs, test0) {
    Solution s;
    vector<int> nums {1, 2, 3, 1, 1, 3};
    EXPECT_EQ(s.numIdenticalPairs(nums), 4);
}

TEST(numIdenticalPairs, test1) {
    Solution s;
    vector<int> nums {1, 1, 1, 1,};
    EXPECT_EQ(s.numIdenticalPairs(nums), 6);
}

TEST(numIdenticalPairs, test2) {
    Solution s;
    vector<int> nums {1, 2, 3};
    EXPECT_EQ(s.numIdenticalPairs(nums), 0);
}