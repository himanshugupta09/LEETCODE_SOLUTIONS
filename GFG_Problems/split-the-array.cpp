//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int mod = 1e9+7;
    long long getPow(long a,long long b){
        if(b==0)
        {
            return 1;
        }
        
        long long res = 1;
        while(b>0)
        {
            if(b&1) res = res*a;
            a = a*a;
            b >>= 1;
        }
        return res;
    }
    int countgroup(vector<int>& arr) {
        // Complete the function
        int wxr = 0;
        int n =  arr.size();
        for(int i:arr)
        {
            wxr ^= i;
        }
        if(wxr == 0)
        {
           return (getPow(2,n-1)-1)%mod;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends
