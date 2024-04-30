//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
         int row[4]={1,0,0,-1};
    int col[4]={0,-1,1,0};
    string dirs="DLRU";
    
    bool isPossible(int x,int y,vector<vector<int>>&m,int n,vector<vector<bool>>&vis){
        if(x>=0 && x<n && y>=0 &&y<n && m[x][y]==1 && vis[x][y]==0)return 1;
        return 0;
    }
    
    
    void solve(int x,int y,vector<string>&ans,string &path,vector<vector<int>>&m,int n,vector<vector<bool>>&vis){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        vis[x][y]=1;
        
       for(int k=0;k<4;k++){
           int newx=x+row[k];
           int newy=y+col[k];
           if (isPossible(newx,newy,m,n,vis)){
               path.push_back(dirs[k]);
               solve(newx,newy,ans,path,m,n,vis);
               path.pop_back();
           }
       }
        vis[x][y]=0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        if(m[0][0]==0)return ans;
        string path="";
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        solve(0,0,ans,path,m,n,vis);
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
