//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int n, int m){
        // code here
        
        int lo = 2;
        int hi = 32;
        
        while(lo <= hi)
        {
            int md = lo + (hi - lo)/2;
            
            int dig = (int)(log(n)/log(md)+1);
            
            if(dig == m)
            {
                return "Yes";
            }
            else if(dig < m)
            {
                hi = md - 1;
            }
            else{
                lo = md + 1;
            }
        }
        
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends
