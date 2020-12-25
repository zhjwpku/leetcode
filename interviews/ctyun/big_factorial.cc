#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string multi_helper(string &s, string &t) {
    if (s == "0" || t == "0") {
        return "0";
    }
    int l1 = s.size();
    int l2 = t.size();

    string res(l1 + l2, '0');
    for (int i = l1 - 1; i >= 0; i--) {
        int step = 0;
        for (int j = l2 - 1; j >= 0; j--) {
            int mul = (s[i] - '0') * (t[j] - '0');
            int sum = res[i + j + 1] - '0' + step + (mul % 10);
            res[i + j + 1] = sum % 10 + '0';
            step = sum / 10 + mul / 10;
        }
        res[i] += step;
    }
    for (int i = 0; i < l1 + l2; i++) {
        if (res[i] != '0') {
            return res.substr(i);
        }
    }
    return "0";
}

string multi(int num) {
    string res = "1";
    for (int i = 2; i <= num; i++) {
        stringstream ss;
        ss << i;
        string tmp;
        ss >> tmp;
        res = multi_helper(res, tmp);
    }
    return res;
}
};

TEST(test1, test1) {
    Solution s;
    cout << s.multi(4) << endl;
}

