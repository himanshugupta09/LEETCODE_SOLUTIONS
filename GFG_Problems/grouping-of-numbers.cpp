//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        // code here
        vector<int>temp(K,0);
        
        for(int i=0;i<N;i++)
        {
            temp[arr[i]%K]++;
        }
        int res = temp[0]>0;
        
        for(int i=1;i<=K-i;i++)
        {
            
            if(i == K-i){
            res += temp[K/2]>0;
            break;
            }
            res += max(temp[i],temp[K-i]);
            
        }
        res = max(1,res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
