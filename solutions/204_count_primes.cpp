#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
	if (n == 2)
		return true;
	int edge = (int)sqrt(double(n));

	for (int i = 2; i <= edge; i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

int countPrimes_TLE(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n == 3) return 2;
	int cnt = 2;

	for (int i = 5; i <= n; i+=2) {
		if (isPrime(i))
			cnt++;
	}
	return cnt;
}

int countPrimes(int n) {
	vector<bool> prime(n, true);
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i < sqrt(n); ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= n; j+=i) {
				prime[j] = false;
			}
		}
	}

	return count(prime.begin(), prime.end(), true);
}

int main() {
	int n;
	while (cin >> n) {
		cout << countPrimes(n) << endl;
	}
	return 0;
}
