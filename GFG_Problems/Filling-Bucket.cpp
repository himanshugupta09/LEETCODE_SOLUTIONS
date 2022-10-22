//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int md = 1e8;
  
    int fillingBucket(int N) {
        // code here
        vector<int>dp(N+1,0);
        dp[0] = 1;
        for(int i=1;i<=N;i++)
        {
            dp[i] = (dp[i-1] + dp[i-2])%md;
            
        }
        return dp[N];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
