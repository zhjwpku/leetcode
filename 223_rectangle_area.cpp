#include <iostream>
using namespace std;

int computeArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int total = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3);

	if (x3 >= x2 || x1 >= x4 || y1 >= y4 || y3 >= y2)
		return total;

	vector <int> h;
	vector <int> v;
	h.push_back(x1);
	h.push_back(x2);
	h.push_back(x3);
	h.push_back(x4);
	v.push_back(y1);
	v.push_back(y2);
	v.push_back(y3);
	v.push_back(y4);

	sort(h.begin(), h.end());
	sort(v.begin(), v.end());

	return total - (h[2] - h[1]) * (v[2] - v[1]);
}
