class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }
    long long modInverse(long long a) {
        return power(a, MOD - 2);
    }

    long long C(long long n, long long r) {
        if (r < 0 || r > n) return 0;

        long long ans = 1;

        for (long long i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) % MOD;
            ans = ans * modInverse(i) % MOD;
        }

        return ans;
    }
    int numberOfSets(int n, int k) {
        return C(n+k-1,2*k);
    }
};  