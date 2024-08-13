//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int hi = n;
        long long int low = 1;
        long long int res = INT_MIN;
        while(low <= hi)
        {
            long long int mid = (low+hi)/2;
            if(mid*mid <= n)
            {
                res = max(res,mid);
                low = mid+1;
            }
            else
            {
                hi = mid-1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
