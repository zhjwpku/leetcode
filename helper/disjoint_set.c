/*
 * https://en.wikipedia.org/wiki/Disjoint-set_data_structure
 */

#define MAX_N   100

int parent[MAX_N];      // parent of the node
int rank[MAX_N];        // rank of the tree

void init(n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 1;
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

    if (rank[x] > rank[y]) {
        parent[y] = x;
    } else if (rank[x] == rank[y]) {
        parent[y] = x;
        rank[x]++;
    } else {
        parent[x] = y;
    }
}

int isSameSet(int x, int y) {
    return find(x) == find(y);
}
