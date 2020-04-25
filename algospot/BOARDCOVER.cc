#include <iostream>
#include <vector>
using namespace std;

const int coverDir[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

bool canCover(const vector<string> &matrix, int y, int x, int direct)
{
    for (int i = 0; i < 3; i++) {
        int yy = y + coverDir[direct][i][0];
        int xx = x + coverDir[direct][i][1];
        if (yy < 0 || yy >= matrix.size() || xx < 0 || x >= matrix[0].size()) {
            return false;
        }
        if (matrix[yy][xx] != '.') {
            return false;
        }
    }
    return true;
}

void doCover(vector<string> &matrix, int y, int x, int direct) {
    for (int i = 0; i < 3; i++) {
        matrix[y + coverDir[direct][i][0]][x + coverDir[direct][i][1]] = '#';
    }
}

void unCover(vector<string> &matrix, int y, int x, int direct) {
    for (int i = 0; i < 3; i++) {
        matrix[y + coverDir[direct][i][0]][x + coverDir[direct][i][1]] = '.';
    }
}

int solve(vector<string> &matrix)
{
    // find the first .
    int y = -1, x = -1;
    for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == '.') {
                y = i;
                x = j;
                goto findDot;
            }
        }
    }
findDot:
    if (y == -1) {
        return 1;
    }

    int ret = 0;

    for (int i = 0; i < 4; i++) {
        if (canCover(matrix, y, x, i)) {
            doCover(matrix, y, x, i);
            ret += solve(matrix);
            unCover(matrix, y, x, i);
        }
    }

    return ret;
}

int main()
{
    int c;
    cin >> c;
    while (c--) {
        int h, w;
        cin >> h >> w;
        vector<string> matrix;
        for (int i = 0; i < h; i++) {
            string row;
            cin >> row;
            matrix.push_back(row);
        }
        cout << solve(matrix) << endl;
    }

    return 0;
}