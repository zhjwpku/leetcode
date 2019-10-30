/*
 * https://leetcode-cn.com/problems/permutations/
 */

class Solution {
    void permute(vector<int>& nums, vector<int> path, vector<vector<int> >& result) {
        if (nums.size() == 1) {
            path.push_back(nums[0]);
            result.push_back(path);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                int tmp = nums[i];
                nums.erase(nums.begin() + i);
                path.push_back(tmp);
                permute(nums, path, result);
                nums.insert(nums.begin() + i, tmp);
                path.pop_back();
            }
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int> > res;
        permute(nums, path, res);

        return res;
    }
};
