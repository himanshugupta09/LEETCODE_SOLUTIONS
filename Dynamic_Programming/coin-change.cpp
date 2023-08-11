//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        /*
        code here.
        memset(memo, -1, sizeof(memo)); 
        if(sum == 0)
        {
            return 1;
        }
        if(N == 0 || sum < 0)
        {
            return 0;
        }
        
        if(memo[N][sum] != -1)
        {
            return memo[N][sum];
        }
        
        int way1 = count(coins,N,sum-coins[N-1]); // include coins
        int way2 = count(coins,N-1,sum);   // Not include
        
        memo[N][sum] = way1 + way2;
        return memo[N][sum];
       */
       long long dp[N+1][sum+1];
       for(int i=0;i<=N;i++)
       {
           dp[i][0] = 1;
       }
       for(int i=0;i<=sum;i++)
       {
           dp[0][i] = 0;
       }
       for(int i=1;i<=N;i++)
       {
           for(int j=1;j<=sum;j++)
           {
               if(coins[i-1] <= j)
               {
                   dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
               }
               else
               {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[N][sum];
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
