//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    
    
    int getSumofDigits(int n)
    {
        int res = 0;
        
        while(n != 0)
        {
            res += n%10;
            n /= 10;
            
        }
        return res;
    }
    int smithNum(int n) {
        // code here
        int sod = getSumofDigits(n);
        int cur = n;
         int sum2=0; 
        bool prime=true; 
        for(int i=2; i*i<=n; i++) {
            while(cur%i==0) {
                sum2+=getSumofDigits(i); 
                cur/=i; 
                prime=false; 
            }
        }
        if(cur>1) sum2+=getSumofDigits(cur); 
        return (sod==sum2 && prime==false);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
