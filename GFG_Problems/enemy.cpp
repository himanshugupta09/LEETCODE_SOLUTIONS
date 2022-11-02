//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    /*
    
    
    As we need to find the maximum area then we will
    be finding out the maximum adjacent length of row and column can
    be used to form our maximum area.
    
    
    We store the row and column in different two vectors. 
    Now we will sort the individual vectors and find the maximum 
    difference between adjacent elements.
    
    
    After finding out the maximum difference of adjacent elements of row and column we just 
    need to multiply those and return .
    
    */
    
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            
            int x = 0,y = 0;
            
            vector<int>row,col;
            
            row.push_back(0);
            col.push_back(0);
            
            for(int i=0;i<enemy.size();i++)
            {
                row.push_back(enemy[i][0]);
                col.push_back(enemy[i][1]);
            }
            
            row.push_back(n+1);
            col.push_back(m+1);
            
            sort(row.begin(),row.end());
            sort(col.begin(),col.end());
            
            for(int i=1;i<col.size();i++)
            {
                x = max(x,row[i]-row[i-1]-1);
                y = max(y,col[i]-col[i-1]-1);
            }
            
            
            return x*y;
            
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends
