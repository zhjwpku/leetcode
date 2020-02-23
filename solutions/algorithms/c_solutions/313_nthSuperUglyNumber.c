/*
 https://leetcode-cn.com/problems/super-ugly-number
 */

int dp[100000] = {1};
int nthSuperUglyNumber(int n, int* primes, int primesSize){
    int *store = malloc(primesSize * sizeof(int));
    memset(store, 0, primesSize * sizeof(int));

    for (int i = 1; i < n; i++) {
        int min = INT_MAX;

        for (int j = 0; j < primesSize; j++) {
            int tmp = primes[j] * dp[store[j]];
            if (tmp < min) {
                min = tmp;
            }
        }

        dp[i] = min;

        for (int j = 0; j < primesSize; j++) {
            if (min == primes[j] * dp[store[j]]) {
                store[j] ++;
            }
        }
    }

    return dp[n];
}