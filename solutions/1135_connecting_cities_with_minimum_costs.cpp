#include <iostream>
#include <queue>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

#define MAX_N   10000

int parent[MAX_N];      // parent of the node
int ranks[MAX_N];        // rank of the tree

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranks[i] = 1;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        // x and y are in the same set, do nothing
        return;
    }

    if (ranks[x] > ranks[y]) {
        parent[y] = x;
    } else if (ranks[x] == ranks[y]) {
        parent[y] = x;
        ranks[x]++;
    } else {
        parent[x] = y;
    }
}

int isSameSet(int x, int y) {
    return find(x) == find(y);
}

struct Edge {
    int u, v, w;    // u -> v weights w
};

bool operator<(const Edge &lhs, const Edge &rhs) {
    return lhs.w > rhs.w;
}

int minimumCost(int N, vector<vector<int>>& connections) {
    init(N);
    priority_queue<Edge> edges;

    for (auto r: connections) {
        edges.emplace(Edge{r[0], r[1], r[2]});
    }

    int mst = 0;
    int cnt = 0;
    while (!edges.empty()) {
        Edge e = edges.top();
        edges.pop();

        if (!isSameSet(e.u, e.v)) {
            union_(e.u, e.v);
            mst += e.w;
            cnt++;
        }

        if (cnt == N - 1) return mst;
    }

    return -1;
}

TEST(minimumCost, test1) {
    int n = 3;
    vector<vector<int>> conections {
        {1,2,5},
        {1,3,6},
        {2,3,1}
    };

    EXPECT_EQ(minimumCost(n, conections), 6);
}
