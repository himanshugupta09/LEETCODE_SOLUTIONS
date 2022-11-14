class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        int ans = 0;



        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int gp=0;gp<n;gp++)
        {
            
            for(int i=0,j=gp;j<n;i++,j++){
                if(gp==0){
                    dp[i][j]=1;
                    ans++;
                }
                else if(gp == 1 and s[i]==s[j]){
                    dp[i][j]=1;
                    ans++;
                }else if(s[i] == s[j] and dp[i+1][j-1] ==1){
                    dp[i][j]=1;
                    ans++;
                }
            }
        }

        return ans;



        }
    
};
