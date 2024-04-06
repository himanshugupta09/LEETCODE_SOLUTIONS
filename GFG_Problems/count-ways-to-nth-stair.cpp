//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        // your code here
        int mod = 1e9+7;
        vector<long long>dp(n+1,0);
        dp[0] = 1;
        
        
        for (int i=1;i<=n;i++)
        {
            if(i%2 == 0)
            {
                dp[i] = dp[i-1]+1;
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        return dp[n]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    // taking count of testcases
    int t;
    cin >> t;

    while (t--) {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends
