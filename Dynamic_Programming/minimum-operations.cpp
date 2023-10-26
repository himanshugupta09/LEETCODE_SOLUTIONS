//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        vector<int>dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        
        if(n <= 1)
        {
            return dp[n];
        }
        dp[2] = 2;
        
        for(int i=3;i<=n;i++)
        {
            if(i%2 == 0)
            {
                dp[i] = dp[i/2]+1;
            }
            else
            {
                dp[i] = dp[i-1]+1;
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends
