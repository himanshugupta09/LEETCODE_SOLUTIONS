//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int>s;
        vector<int>res(n,-1);
        
        s.push(-1);
        
        for(int i=0;i<n;i++)
        {
            int cur = a[i];
            
            if(i == 0)
            {
                res[i] = -1;
                s.push(cur);
                
            }
            else
            {
                if(cur>s.top())
                {
                    res[i] = s.top();
                    s.push(cur);
                    
                    
                }
                else{
                    while(s.top()>=cur)
                    {
                        s.pop();
                        
                    }
                    res[i] = s.top();
                    s.push(cur);
                    
                }
                
                 
            }
            
        }
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
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
