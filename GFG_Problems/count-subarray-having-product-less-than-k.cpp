//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        long long pro = 1;
        int st = 0;
        int e = 0;
        int res = 0;
        while(e < n)
        {
            pro *= a[e];
            
            while(st < e && pro >= k)
            {
                pro /= a[st];
                st++;
            }
            
            if(pro < k)
            {
                res += (e-st)+1;   
            }
            e++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
