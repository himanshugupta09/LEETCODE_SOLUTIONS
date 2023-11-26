//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //int oldN;
    void recur(int N, vector<int> &res){
        if(N>0){
            res.push_back(N);
            recur(N-5, res);
        }
        res.push_back(N);
    }
    
    vector<int> pattern(int N){
        // code here
        vector<int> res;
        recur(N, res);
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
