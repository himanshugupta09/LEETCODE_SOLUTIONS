//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    // code here
	    int md = 1000000007;
	    
	    vector<ll>dp1(n+1,0);
	    vector<ll>dp2(n+1,0);
	    dp1[1] = 1;
	    dp2[1] = 1;
	    
	    
	    for(int i=2;i<=n;i++)
	    {
	        dp1[i] = (dp1[i-1] + dp2[i-1])%md;
	        dp2[i] = dp1[i-1]%md;
	        
	    }
	    
	    return (dp1[n]+dp2[n])%md;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
