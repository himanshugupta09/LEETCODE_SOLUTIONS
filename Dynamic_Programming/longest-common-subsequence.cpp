 class Solution {
        public:
            int longestCommonSubsequence(string s1, string s2) {
                int n = s1.size();
                int m = s2.size();
                vector<int> dp(m+1,0),curr(m+1,0);
                
                for(int i =0;i<=n;i++){
                    for(int j=0;j<=m;j++){
                        if(i == 0) dp[j] = 0;
                        else if(j == 0) curr[j] = 0;
                        else{
                            if(s1[i-1] == s2[j-1]) curr[j] = 1 + dp[j-1];
                            else curr[j] = max(dp[j],curr[j-1]);
                        }
                    }
                    dp = curr;
                }
                
                return dp[m];
            }
        };
