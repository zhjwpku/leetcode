class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;

		int a[256] = {0};
		int b[256] = {0};

		for (int i = 0; i < s.size(); i++)
			a[s[i]] ++;
		for (int i = 0; i < t.size(); i++)
			b[t[i]] ++;

		for (int i = 0; i < 256; i++) {
			if (a[i] != b[i])
				return false;
		}

		return true;
	}
};
