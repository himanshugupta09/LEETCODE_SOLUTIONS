class Solution {
public:
    
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
        {
            return true;
        }
        else if(s1.size() == 1)
        {
            return s1 == s2;
        }
        else
        {
            int n = s1.size();
            vector dp(n+1,vector(n,vector<int>(n)));

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dp[1][i][j] = s1[i] == s2[j];
                }
            }

            for(int l=2;l<=n;l++)
            {
                for(int i=0;i<n+1-l;i++)
                {
                    for(int j=0;j<n+1-l;j++)
                    {
                        for(int nl=1;nl<l;nl++)
                        {
                            const vector<int>& dp1 = dp[nl][i];
                            const vector<int>& dp2 = dp[l-nl][i+nl];

                            dp[l][i][j] |= dp1[j] && dp2[j+nl];
                            dp[l][i][j] |= dp1[j+l-nl] && dp2[j];
                        }
                    }
                }
            }

            return dp[n][0][0];
        }

    }
};
