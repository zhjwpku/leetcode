/*
 * https://leetcode-cn.com/problems/accounts-merge/
 */

class Solution {
    int parent[1010];
    int rank[1010];
    unordered_map<string, int> emailPos;
    unordered_map<int, vector<string>> personEmail;

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void union_(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }

        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else if (rank[x] == rank[y]) {
            parent[y] = x;
            rank[x] ++;
        } else {
            parent[x] = y;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> result;
        for (int i = 0; i < accounts.size(); i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailPos.find(email) != emailPos.end()) {
                    union_(i, emailPos[email]);
                } else {
                    emailPos[email] = i;
                }
            }
        }

        for (auto it: emailPos) {
            int pos = find(it.second);
            if (personEmail.find(pos) != personEmail.end()) {
                personEmail[pos].push_back(it.first);
            } else {
                vector<string> tmp;
                tmp.push_back(accounts[pos][0]);
                tmp.push_back(it.first);
                personEmail[pos] = tmp;
            }
        }

        for (auto it: personEmail) {
            sort(it.second.begin() + 1, it.second.end());
            result.push_back(it.second);
        }

        return result;
    }
};
