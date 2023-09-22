class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Get the lengths of the input strings.
        int n = s.size();  // Length of string 's'.
        int m = t.size();  // Length of string 't'.
        
        // Create a 2D DP (dynamic programming) table with dimensions (n+1) x (m+1) and initialize it with zeros.
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Iterate through both strings, character by character.
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // Check if the current characters of 's' and 't' match.
                if(s[i-1] == t[j-1]) {
                    // If they match, update the DP table by incrementing the count of matching characters.
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    // If they don't match, update the DP table with the maximum count of matching characters so far.
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // Check if the length of the longest subsequence of 's' in 't' is equal to the length of 's'.
        return dp[n][m] == n ? true : false;
    }
};
