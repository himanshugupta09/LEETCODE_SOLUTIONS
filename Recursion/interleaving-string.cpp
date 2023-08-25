class Solution {
public:

    bool isInterleave_check(string s1,string s2,string s3,int i,int j,int k,int n1,int n2,int n3,vector<vector<int>> &dp)
    {
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(i == n1 && j == n2 && k == n3)
        {
            return true;
        }
        bool x = false,y = false;

        if(i != n1)
        {
            if(s1[i] == s3[k])
            {
                x = isInterleave_check(s1,s2,s3,i+1,j,k+1,n1,n2,n3,dp);
            }
        }
        if(j != n2)
        {
            if(s2[j] == s3[k])
            {
                y = isInterleave_check(s1,s2,s3,i,j+1,k+1,n1,n2,n3,dp);
            }
        }

        return dp[i][j] = x||y;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));

        return isInterleave_check(s1,s2,s3,0,0,0,n1,n2,n3,dp);
    }
};
