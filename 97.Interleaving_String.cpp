class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length()) return false;
		if (s1.length() < s2.length()) swap(s1, s2);
		int m = s1.length(), n = s2.length();
			
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int j = 1; j <= n; j++) {
            dp[j] = s3[j - 1] == s2[j - 1] && dp[j - 1];
        }

        for (int i = 1; i <= m; i++) {
            dp[0] = s3[i - 1] == s1[i - 1] && dp[0];
            for (int j = 1; j <= n; j++) {
                dp[j] = (s3[i + j - 1] == s1[i - 1] && dp[j]);
                dp[j] = dp[j] || (s3[i + j - 1] == s2[j - 1] && dp[j - 1]);
            }
        }
        return dp.back();
    }
};
