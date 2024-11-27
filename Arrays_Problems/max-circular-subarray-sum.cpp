//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int maxSum = INT_MIN;
        int loc = 0;
        int tot = accumulate(arr.begin(),arr.end(),0);
        for(int i=0;i<arr.size();i++)
        {
            loc += arr[i];
            maxSum = max(maxSum,loc);
            if(loc < 0)
            {
                loc  = 0;
            }
        }
        loc = 0;
        int minSum   =  INT_MAX;
        for(int i=0;i<arr.size();i++)
        {
            loc += arr[i];
            minSum = min(minSum,loc);
            if(loc > 0)
            {
                loc = 0;
            }
        }
        tot -= minSum;
        return max(maxSum,tot);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
