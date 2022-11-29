//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getCount(int N) {
        // code here
       long int cnt = 0;
       
       for(long int l=1;l*(l+1)<2*N;l++)
       {
           double a = (1.0*N - (l*(l+1))/2)/(l+1);
           if(a-(int)a == 0.0)
           {
               cnt++;
           }
       }
       return cnt;
       
       
        
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
        cout << ob.getCount(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
