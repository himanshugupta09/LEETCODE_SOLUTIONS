//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        vector<int> A(N, -1e9), B(N, 1e9);
        int cur = -1e9;
        for(int i=0;i<N;i++)
        {
            if(S[i] == '1')
            {
                cur = i;
            }
            A[i] = cur;
        }
        cur = 1e9;
        for(int i=N-1;i>=0;i--)
        {
            if(S[i] == '1')
            {
                cur = i;
            }
            B[i] = cur;
        }
        
        for(int i=0;i<N;i++)
        {
            if(abs(A[i]-i)>X && abs(B[i]-i)>X)
            {
                return false;
            }

        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends
