//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(string S1, string S2){
        
        int n = S1.size();
        int m = S2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
                
            }
        }
        
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(S1[i-1] == S2[j-1])
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    
                }
            }
        }
        
        return dp[n][m];
        
        
        
        
        // code here
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends
