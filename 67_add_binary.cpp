class Solution {
public:
	string addBinary(string a, string b) {
		string res = "";
		int n = max(a.size(), b.size());
		int c = 0;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		for (int i = 0; i < n; i++) {
			int ai = i < a.size() ? a[i] - '0' : 0;
			int bi = i < b.size() ? b[i] - '0' : 0;
			int val = (ai + bi + c) % 2;
			c = (ai + bi + c) / 2;
			res = ((val == 0) ? "0" : "1") + res;
		}

		if (c)
			res = "1" + res;
		return res;
	}
};
