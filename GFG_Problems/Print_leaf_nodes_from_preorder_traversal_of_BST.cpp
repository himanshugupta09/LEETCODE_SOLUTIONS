//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        // code here
        vector<int>res;
        
        stack<int>st;
        
        for(int i=0;i<N;i++)
        {
            if(!st.empty() && st.top() < arr[i])
            {
                int p = st.top();
                st.pop();
                
                if(!st.empty() && st.top() < arr[i])
                {
                    res.push_back(p);
                    
                    while(!(st.empty()) && st.top() < arr[i])
                    {
                        st.pop();
                        
                    }
                }
            }
            st.push(arr[i]);
            
        }
        res.push_back(st.top());
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
