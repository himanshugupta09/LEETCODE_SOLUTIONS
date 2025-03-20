//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int s1 = INT_MIN,s2 = INT_MIN;
        int b1 = INT_MAX,b2  = INT_MAX;
        for(int i=0;i<n;i++)
        {
            b1= min(b1,prices[i]);
            s1  = max(s1,prices[i]-b1);
            b2 = min(b2,prices[i]-s1);
            s2 = max(s2,prices[i]-b2);
        }
        return s2;
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
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
