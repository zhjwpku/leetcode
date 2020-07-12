#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    struct Point {
        int idx;
        double dis;
        Point(int idx, double dis): idx(idx), dis(dis) {}
        bool operator<(const Point& other) const {
            return dis < other.dis;
        }
    };
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<list<pair<int, double>>> adj(n);
        vector<double> dis(n, 0.0);
        priority_queue<Point> pq;


        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }

        dis[start] = 1.0;
        pq.push({start, dis[start]});

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int idx = p.idx;

            for (auto iter = adj[idx].begin(); iter != adj[idx].end(); iter++) {
                if (dis[idx] * iter->second > dis[iter->first]) {
                    dis[iter->first] = dis[idx] * iter->second;
                    pq.push({iter->first, dis[iter->first]});
                }
            }
        }

        // for (int i = 0; i < dis.size(); i++) {
        //     cout << dis[i] << ' ';
        // }
        // cout << endl;

        return dis[end];
    }
};

TEST(maxProbability, test0) {
    Solution s;
    vector<vector<int>> edges {{1, 4}, {2, 4}, {0, 4}, {0, 3}, {0, 2}, {2, 3}};
    vector<double> succProb {0.37, 0.17, 0.93, 0.23, 0.39, 0.04};
    EXPECT_FLOAT_EQ(s.maxProbability(5, edges, succProb, 3, 4), 0.2139);
}