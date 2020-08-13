#include <string>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    string add(string num1, string num2) {
        if (num1.size() == 0) {
            return num2;
        }
        if (num2.size() == 0) {
            return num1;
        }

        int c = 0;
        int i = 0;
        string res;
        res.reserve(max(num1.size(), num2.size()) + 1);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        while (i < num1.size() || i < num2.size()) {
            if (i < num1.size()) {
                c += num1[i] - '0';
            }

            if (i < num2.size()) {
                c += num2[i] - '0';
            }

            res.push_back((c % 10) + '0');
            c /= 10;
            i++;
        }

        if (c) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string mutilply_one_num(string num, int n) {
        if (n == 0) {
            return "";
        }
        if (n == 1) {
            return num;
        }

        string res;
        res.reserve(num.size() + 1);
        int c = 0;
        for (auto it = num.rbegin(); it != num.rend(); it++) {
            c += (*it - '0') * n;
            res.push_back((c % 10) + '0');
            c /= 10;
        }

        if (c) {
            res.push_back(c + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        if (num1.size() == 0 || num2.size() == 0) {
            return "";
        }

        string res = "";
        string zeros = "";
        for (auto it = num1.rbegin(); it != num1.rend(); it++) {
            int n = *it - '0';
            string tmp = mutilply_one_num(num2, n);
            if (tmp != "0") {
                tmp += zeros;
                res = add(res, tmp);
            }
            zeros.push_back('0');
        }

        return res;
    }
};

TEST(multiply, test0) {
    string num1 = "0";
    string num2 = "0";
    string res = "0";
    Solution s;

    EXPECT_EQ(s.multiply(num1, num2), res);
}