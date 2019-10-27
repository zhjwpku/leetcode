/**
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 */

class Solution {
private:
    void getAandBFromStack(int& a, int& b, stack<int>& s) {
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b;
        for(int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];

            if (token == "+") {
                getAandBFromStack(a, b, s);
                s.push(a + b);
            } else if (token == "-") {
                getAandBFromStack(a, b, s);
                s.push(b - a);
            } else if (token == "*") {
                getAandBFromStack(a, b, s);
                s.push(a * b);
            } else if (token == "/") {
                getAandBFromStack(a, b, s);
                s.push(b / a);
            } else {
                stringstream ss(token);
                ss >> a;
                s.push(a);
            }
        }

        return s.top();
    }
};
