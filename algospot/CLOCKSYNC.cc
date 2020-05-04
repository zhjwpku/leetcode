
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

const int SWITCHS = 10;
const int CLOCKS = 16;
const int INF = 9999;

int solve(vector<int> &clocks, int swtch);
bool isAligned(const vector<int> &clocks);
// 按下第 idx 个 button
void press(vector<int> &clocks, int idx);

const char linked[SWITCHS][CLOCKS+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

int main()
{
    int c;
    cin >> c;
    while (c--) {
        vector<int> clocks(CLOCKS, 0);
        for (int i = 0; i < CLOCKS; i++) {
            cin >> clocks[i];
        }

        int res = solve(clocks, 0);
        if (res >= INF) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
        }
    }

    return 0;
}

int solve(vector<int> &clocks, int swtch)
{
    if (swtch == SWITCHS) {
        return isAligned(clocks) ? 0 : INF;
    }

    int ret = INF;
    for (int i = 0; i < 4; ++i) {
        ret = min(ret, i + solve(clocks, swtch + 1));
        press(clocks, swtch);
    }

    return ret;
}

bool isAligned(const vector<int> &clocks)
{
    return count_if(clocks.begin(), clocks.end(),
        [](int i) { return i != 12;}) == 0;
}

void press(vector<int> &clocks, int idx)
{
    for (int i = 0; i < CLOCKS; i++) {
        if (linked[idx][i] == 'x') {
            clocks[i] += 3;
            if (clocks[i] == 15) {
                clocks[i] = 3;
            }
        }
    }
}
