//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    //vector<long long>mo()
    long long findNumber(long long N){
        vector<int>arr = {9,1,3,5,7};
        
        long long ans = 0;
        
        while(N)
        {
            int r = N%5;
            
            ans *= 10;
            ans += arr[r];
        
            if(!r) N--;
            N /= 5;
        }
        
        string s = to_string(ans);
        reverse(s.begin(), s.end());
        return stol(s);
        // Code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
