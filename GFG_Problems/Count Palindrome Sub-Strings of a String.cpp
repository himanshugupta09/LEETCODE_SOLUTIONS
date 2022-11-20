//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char S[], int N)
{
    //code here
    
    vector<vector<int>>dp(N+1,vector<int>(N+1,0));
    string  s = "";
    for(int i=0;i<N;i++){
        s+=S[i];
    }
    
    int st = 0,en = 1;
    
    
    for(int i=0;i<N;i++)
    {
       dp[i][i] = 1;
       st = i;
       en = 1;
       
    }
    for(int i=0;i<N-1;i++)
    {
        if(S[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            st = i;
            en = 2;
            
        }
    }
    
    for(int i=2;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int l = j;
            int r = i+j;
            
            if(s[l] == s[r] && dp[l+1][r-1])
            {
                dp[l][r] = 1;
                st = i;
                en = i+1;
                
            }
        }
    }
    
    int res = 0;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(dp[i][j])
            {
                res++;
                
            }
        }
    }
    
    
    return res-N;
    
    
    
}
