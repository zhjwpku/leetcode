#include <iostream>
#include <queue>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    struct Point {
        int x;
        int y;
        int depth;
        inline bool operator<(const Point &rhs) const {
            return depth < rhs.depth;
        }
        inline bool operator>(const Point &rhs) const {
            return depth > rhs.depth;
        }
    };


    inline bool pointValid(const vector<vector<int>> &grid, int x, int y) {
         return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size());
    }

    int bfs(const vector<vector<int>> &grid) {
        vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));
        vector<pair<int, int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        visit[0][0] = 1;
        int maxHeight = grid[0][0];

        priority_queue<Point, vector<Point>, greater<Point>> q;
        q.emplace(Point{0, 0, grid[0][0]});

        while (!q.empty()) {
            Point cur = q.top();
            q.pop();

            if (grid[cur.x][cur.y] > maxHeight) {
                maxHeight = grid[cur.x][cur.y];
            }

            for (auto dir: direct) {
                int nextX = cur.x + dir.first;
                int nextY = cur.y + dir.second;

                if (!pointValid(grid, nextX, nextY) || visit[nextX][nextY]) {
                    continue;
                }

                if (nextX == grid.size() - 1 && nextY == grid[0].size() - 1) {
                    if (grid[nextX][nextY] > maxHeight) {
                        return grid[nextX][nextY];
                    } else {
                        return maxHeight;
                    }
                }

                visit[nextX][nextY] = true;
                q.emplace(Point{nextX, nextY, grid[nextX][nextY]});
            }
        }

        return -1;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};


TEST(swim_in_rising_water, test1) {
    Solution s;
    vector<vector<int>> grid {      // C++ 11 Initializer Lists
        {0,1,2,3,4},
        {24,23,22,21,5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10,9,8,7,6}
    };
    EXPECT_EQ(s.swimInWater(grid), 16);
}