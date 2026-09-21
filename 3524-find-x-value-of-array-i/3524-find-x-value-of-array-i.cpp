class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(k, 0));

        for (int i = 0; i < n; i++) {
            int x = ((nums[i] % k) + k) % k;
            dp[i][x]++;

            if (i > 0) {
                for (int r = 0; r < k; r++) {
                    if (dp[i - 1][r] > 0) {
                        int new_r = (1LL * r * x) % k;
                        dp[i][new_r] += dp[i - 1][r];
                    }
                }
            }
        }

        for (int j = 0; j < k; j++) {
            long long s = 0;
            for (int i = 0; i < n; i++) {
                s += dp[i][j];
            }
            dp[n - 1][j] = s;
        }

        return dp[n - 1];
    }
};
