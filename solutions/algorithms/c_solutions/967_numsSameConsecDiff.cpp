/*
 * https://leetcode-cn.com/problems/numbers-with-same-consecutive-differences/
 */

class Solution {
    void dfs(int pre, int i, int n, int K, vector<int>& res) {
        if (n == 1) {
            res.push_back(pre * 10 + i);
            return;
        }
        
        if (K == 0) {
            dfs(pre * 10 + i, i, n - 1, K, res);
            return;
        }
        
        if (i - K >= 0) {
            dfs(pre * 10 + i, i - K, n - 1, K, res);
        }
        
        if (i + K < 10) {
            dfs(pre * 10 + i, i + K, n - 1, K, res);
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        
        if (N == 1) {
            for (int i = 0; i < 10; i++) {
                res.push_back(i);
            }

            return res;
        }
        
        for (int i = 1; i <= 9; i++) {
            if (K == 0) {
                dfs(i, i, N - 1, K, res);
            } else {
                if (i - K >= 0) {
                    dfs(i, i - K, N - 1, K, res);
                }
                if (i + K < 10) {
                    dfs(i, i + K, N - 1, K, res);
                }
            }
        }
        
        return res;
    }
};
