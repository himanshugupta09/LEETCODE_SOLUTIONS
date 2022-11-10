//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        // code here
        
        long long  ans = INT_MIN;
        queue<long long>q;
        
        for(long long i=1;i<=9;i++)
        {
            q.push(i);
        }
        
        while(!q.empty())
        {
            long long f = q.front();
            ans = max(ans,f);
            
            q.pop();
            
            int l = f%10;
            int m = f*10+l+1;
            int d = f*10+l-1;
            
            if(l == 0)
            {
                if(m<=X)
                {
                    q.push(m);
                }
            }
            else if(l == 9)
            {
                if(d <= X){
                    q.push(d);
                }
            }
            else{
                if(d<=X) q.push(d);
                if(m<=X) q.push(m);
                
            }
        }
        
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
