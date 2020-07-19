#include <vector>
#include <string>
#include <list>
#include <queue>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<list<int>> adjacentList(n);
        for (auto &edge: edges) {
            adjacentList[edge[0]].push_back(edge[1]);
        }

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                ans[i] += labels[i] == labels[cur] ? 1 : 0;
                for (auto iter = adjacentList[cur].begin(); iter != adjacentList[cur].end(); iter ++) {
                    q.push(*iter);
                }
            }
        }

        for (auto ele: ans) {
            cout << ele << ' ';
        }
        cout << endl;

        return ans;
    }
};

TEST(countSubTrees, test0) {
    vector<vector<int>> edges {
        {0,1}, {0,2}, {1,4}, {1,5}, {2,3}, {2,6}
    };

    vector<int> output {2,1,1,1,1,1,1};

    Solution s;
    EXPECT_EQ(s.countSubTrees(7, edges, "abaedcd"), output);
}

TEST(countSubTrees, test1) {
    vector<vector<int>> edges {
        {0,2}, {1,2}, {0,3}
    };

    vector<int> output {1,2,1,1};

    Solution s;
    EXPECT_EQ(s.countSubTrees(4, edges, "aeed"), output);
}