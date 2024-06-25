//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
         int m=mat[0].size();
        int n=mat.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        k%=m;
        if(k==0)
        return mat;
        for(int i=0;i<n;i++)
        {
            int x=0;
            for(int j=k;j<m;j++)
            {
                ans[i][x]=mat[i][j];
                x++;
            }
            
            for(int j=0;j<k;j++)
            {
                ans[i][x]=mat[i][j];
                x++;
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends
