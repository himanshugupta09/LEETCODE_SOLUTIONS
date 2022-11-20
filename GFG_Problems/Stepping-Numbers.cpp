//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    void solve(int now,int n,int m,int &res)
    {
        if(now > m) return;
        if(now >= n && now <= m) res++;
        
        int ls = now%10;
        if(ls == 9)
        {
            solve(now*10+8,n,m,res);
        }
        else if(ls == 0)
        {
            solve(now*10+1,n,m,res);
        }
        else{
            solve(now*10 + (ls+1),n,m,res);
            solve(now*10 + (ls-1),n,m,res);
            
            
        }
    }

    int steppingNumbers(int n, int m)
    {
        // Code Here
        int res = 0;
        if(n == 0)
        {
            res++;
            
        }
        for(int i=1;i<=9;i++)
        {
            solve(i,n,m,res);
            
        }
        
        
        return res;
        
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends
