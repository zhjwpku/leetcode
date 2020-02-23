/**
 * https://leetcode-cn.com/problems/basic-calculator/
 * hint: use double stack
 */

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> oprs;
        int a, b;
        char opr;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                b = s[i] - '0';
                while (i+1 < s.size() && isdigit(s[i+1])) {
                    cout << i << endl;
                    i++;
                    b = b * 10 + (s[i] - '0');
                }

                if (nums.empty()) {
                    nums.push(b);
                } else if (oprs.top() == '(') {
                    nums.push(b);
                } else {
                    a = nums.top();
                    nums.pop();
                    opr = oprs.top();
                    oprs.pop();

                    switch (opr) {
                        case '+':
                            nums.push(a + b);
                            break;
                        case '-':
                            nums.push(a - b);
                            break;
                    }
                }
            } else if (s[i] == '(') {
                oprs.push(s[i]);
            } else if (s[i] == ')') {
                oprs.pop();
                if (oprs.empty()) {
                    continue;
                }
                switch (oprs.top()) {
                    case '+':
                        b = nums.top();
                        nums.pop();
                        a = nums.top();
                        nums.pop();
                        nums.push(a + b);
                        break;
                    case '-':
                        b = nums.top();
                        nums.pop();
                        a = nums.top();
                        nums.pop();
                        nums.push(a - b);
                        break;
                    case '(':
                        break;
                }
                oprs.pop();
            } else if (s[i] == '+' || s[i] == '-') {
                oprs.push(s[i]);
            }
        }

        return nums.top();
    }
};
