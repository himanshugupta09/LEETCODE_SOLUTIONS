//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        vector<int>res;
        int upper=0,lower=R-1,left=0,right=C-1;
        int i=0,j=0;
        while(res.size()<R*C)
        {
            
            i=upper;
            for(int j=left;j<=right;j++)
            {
                res.push_back(a[i][j]);
            }
            upper+=1;
            if(res.size()==R*C)
            break;
            j=right;
            for(int i=upper;i<=lower;i++)
            {
                 res.push_back(a[i][j]);
            }
            right-=1;
            if(res.size()==R*C)
            break;
            i=lower;
            for(int j=right;j>=left;j--)
            {
                res.push_back(a[i][j]);
            }
            lower-=1;
            if(res.size()==R*C)
            break;
            j=left;
            for(int i=lower;i>=upper;i--)
            {
                 res.push_back(a[i][j]);
            }
           left+=1;
            
        }
         reverse(res.begin(),res.end());
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
