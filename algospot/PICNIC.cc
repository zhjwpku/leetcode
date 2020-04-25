#include <iostream>
#include <vector>

using namespace std;

int helper(const vector<vector<bool>> &relations, vector<bool> &taken) {
    int firstFree = -1;
    for (int i = 0; i < taken.size(); i++) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) {
        return 1;
    }
    int ret = 0;
    for (int pairWith = firstFree+1; pairWith < relations.size(); pairWith++) {
        if (!taken[pairWith] && relations[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += helper(relations, taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }

    return ret;
}

int main()
{
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> relations(n, vector<bool>(n, false));
        vector<bool> taken(n, false);
        int cnt = m;
        while (cnt--) {
            int x, y;
            cin >> x >> y;
            relations[x][y] = true;
            relations[y][x] = true;
        }
        if (m < n - 1) {
            cout << 0 << endl;
        } else {
            cout << helper(relations, taken) << endl;
        }
    }

    return 0;
}
