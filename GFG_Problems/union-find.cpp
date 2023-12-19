//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to merge two nodes a and b.
   
    int find_set(int a,int par[])
    {
        if(a == par[a])
        {
            return a;
        }
        return par[a] = find_set(par[a],par);
    }
    void union_( int a, int b, int par[], int rank1[]) 
    {
        int n1  = find_set(a,par);
        int n2 = find_set(b,par);
        
        if(rank1[n1] > rank1[n2])
        {
            par[n2] = n1;
            
        }
        else if(rank1[n2] > rank1[n1])
        {
            par[n1] = n2;
        }
        else
        {
            par[n1] = n2;
            rank1[n2]++;
        }
        
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        //code here
        return find_set(x,par) == find_set(y,par);
        
    }
};

//{ Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}

// } Driver Code Ends
