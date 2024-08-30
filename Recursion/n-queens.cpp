//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col,vector<vector<bool>>&board,vector<vector<int>>&res,vector<int>&leftR,vector<int>&upperD,vector<int>&lowerD,int n)
    {
        if(col == n)
        {
            vector<int>t;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(board[j][i])
                    {
                        t.push_back(j+1);
                    }
                }
            }
            res.push_back(t);
            return;
        }
        
        for(int row = 0;row<n;row++){
            if(leftR[row] == 0 && lowerD[row+col] == 0 && upperD[n-1+col-row] == 0){
                
                
                board[row][col] = 1;
                leftR[row] = 1;
                lowerD[row+col] = 1;
                upperD[n-1+col-row] = 1;
                solve(col+1,board,res,leftR,upperD,lowerD,n);
                board[row][col] = 0;
                leftR[row] = 0;
                lowerD[row+col] = 0;
                upperD[n-1+col-row] = 0;
                
            }
            
    }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>res;
        if(n == 1)
        {
            return {{1}};
        }
        vector<vector<bool>>board(n,vector<bool>(n,0));
        vector<int>leftR(n,0),upperD(2*n-1,0),lowerD(2*n-1,0);
        solve(0,board,res,leftR,upperD,lowerD,n);
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
