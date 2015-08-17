class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mymap;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			mymap[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (mymap.find(target - nums[i]) != mymap.end() && 
				i != mymap[target-nums[i]])
			{
				res.push_back(i + 1);
				res.push_back(mymap[target-nums[i]] + 1 );
				break;
			}
		}

		return res;
	}
};
