//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long int mod  = 1e9+7;
    int Maximize(vector<int> &arr) {
        // Complete the function
        sort(arr.begin(),arr.end());
        long long res = 0;
        int n = arr.size();
        const long long MOD = 1000000007;
        
        // Calculate the sum of arr[i] * i
        for(int i = 0; i < n; ++i) {
            res = (res + i * (long long)arr[i]) % MOD;
        }
        
        return res;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends
