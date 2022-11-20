//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        
        
        
        int sm = 0;
        
        int cl = 0;
        
        int mxl = 0;
        
        for(int i=0;i<n;i++)
        {
            sm +=  A[i];
            
            if(A[i] == 0 && mxl == 0)
            {
                mxl = 1;
            }
            if(sm == 0){
                mxl = i+1;
                
            }
            
            if(mp.find(sm) != mp.end())
            {
                mxl = max(mxl,i-mp[sm]);
                
            }
            else{
                mp[sm] = i;
                
            }
        }
        
        return mxl;
        
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
