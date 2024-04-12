//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        long long res = 0;
        for(int i=0;i<64;i++)
        {
            long long st = 0;
            for(int j=0;j<n;j++)
            {
                (((arr[j] >> i) &1) == 1) ? st+=1 : st; 
            }
            long long t = st*(st-1)/2;
            res += pow(2,i)*t;
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
