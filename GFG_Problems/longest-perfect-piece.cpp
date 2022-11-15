//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        
        int i=0;
        int j=0;
        
        set<int>s;
        
        int mx,mn;
        
        int res=1;
        
        while(j<N)
        {
            s.insert(arr[j]);
            mx = *(s.rbegin());
            mn = *(s.begin());
            
            if(mx-mn <= 1)
            {
                res = max(res,j-i+1);
                j++;
                
            }
            else{
                while(mx-mn>1)
                {
                    s.erase(arr[i]);
                    mx = *(s.rbegin());
                    mn = *(s.begin());
                    i++;
                }
            }
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
