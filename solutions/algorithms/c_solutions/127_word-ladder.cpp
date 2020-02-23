/*
 * https://leetcode-cn.com/problems/word-ladder/
 */

class Solution {
private:
    bool f(const string& a, const string& b) {
        int num = 0;
        for(int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                num ++;
            }
            if (num > 1) return false;
        }

        if (num == 1) return true;
        return false;
    }
    bool helper(queue<string> &q, string &endWord, set<string> &s, int &step) {
        int num = q.size();
        while(num --) {
            string word = q.front();
            q.pop();
            if (word == endWord) {
                return true;
            }

            for(auto it = s.begin(); it != s.end(); ) {
                if(f(*it, word)) {
                    q.push(*it);
                    it = s.erase(it);
                } else {
                    ++it;
                }
            }
        }

        if (q.empty()) return false;
        step ++;
        return helper(q, endWord, s, step);
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) {
            return 0;
        }
        set<string> s;
        for (string word: wordList) {
            s.insert(word);
        }

        if (s.find(endWord) == s.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int step = 0;
        if (helper(q, endWord, s, step)) {
            return step + 1;
        } else {
            return 0;
        }

    }
};
