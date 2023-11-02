//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int minDist = INT_MAX;
        int x_idx = -1;
        int y_idx = -1;
        
        for(int i=0;i<n;i++)
        {
            if(a[i] == x)
            {
                x_idx = i+1;
            }
            else if(a[i] == y)
            {
                y_idx = i+1;
            }
            if(x_idx != -1 && y_idx != -1)
            {
                minDist = min(minDist,abs(x_idx-y_idx));
            }
        }
        if(x_idx == -1 || y_idx == -1)
        {
            return -1;
        }
        return minDist;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends
