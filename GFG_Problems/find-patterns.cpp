//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        int  res = 0;
        
        int n = S.size();
        int m = W.size();
        
        for(int i=0;i<n;i++)
        {
            int l=0,cr = 0;
            for(int j=i;j<n;j++)
            {
                if(S[j] == W[l])
                {
                    S[j] = '.';
                    cr++;
                    l++;
                }
                if(cr == m)
                {
                    res++;
                    break;
                }
            }
        }
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends
