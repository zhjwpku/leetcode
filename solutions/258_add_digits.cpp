#include <iostream>

using namespace std;

int main()
{
	int a;
	while (cin >> a) {
		while (a >= 10) {
			int tmp = 0;
			while (a != 0) {
				tmp += a%10;
				a = a/10;
			}
			a = tmp;
		}

		cout << a << endl;
	}
}
