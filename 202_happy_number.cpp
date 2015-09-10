#include <iostream>
#include <unordered_map>

using namespace std;

bool isHappy(int n) {
	unordered_map<int, int> mymap;

	while (n !=1) {
		int x = n;
		int sum = 0;
		while (x) {
			sum += (x % 10) * (x % 10);
			x/=10;
		}

		if (mymap.find(sum) != mymap.end())
			return false;
		else
			mymap[sum] = 1;
		n = sum;
	}

	return true;
}

int main() {
	int a;
	while (cin >> a)
		cout << isHappy(a) <<endl;
	return 0;
}
