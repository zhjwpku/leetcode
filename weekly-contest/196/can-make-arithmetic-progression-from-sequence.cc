#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() < 3) {
            return true;
        }
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            if (diff != arr[i] - arr[i-1]) {
                return false;
            }
        }

        return true;

    }
};

TEST(canMakeArithmeticProgression, test0)
{
    Solution s;
    vector<int> arr2 {3, 5};
    EXPECT_TRUE(s.canMakeArithmeticProgression(arr2));
    vector<int> arr1 {1};
    EXPECT_TRUE(s.canMakeArithmeticProgression(arr1));
    vector<int> arr0 {};
    EXPECT_TRUE(s.canMakeArithmeticProgression(arr0));
}

TEST(canMakeArithmeticProgression, test1)
{
    Solution s;
    vector<int> arr {3, 5, 1};
    EXPECT_TRUE(s.canMakeArithmeticProgression(arr));
}

TEST(canMakeArithmeticProgression, test2)
{
    Solution s;
    vector<int> arr {201, 10, -1};
    EXPECT_TRUE(s.canMakeArithmeticProgression(arr));
}
