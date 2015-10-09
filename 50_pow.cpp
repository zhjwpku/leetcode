#include <iostream>
#include <vector>

using namespace std;

double myPow(double x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;

	double v = myPow(x, n/2);

	if (n % 2 == 0) return v*v;
	else return v*v*x;
}

double pow(double x, int n) {
	if (n < 0) return 1.0 / myPow(x, -n);
	else return myPow(x, n);
}

int main() {
	int n;
	double x;
	while (cin >> x >> n) {
		cout << pow(x, n) << endl;
	}

	return 0;
}
