//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        if(N == 0)
        {
            return "";
        }
        if(N == 1)
        {
            return arr[0];
        }
        sort(arr,arr+N);
        
        int sz = min(arr[0].size(),arr[N-1].size());
        
        string fi = arr[0];
        string ls = arr[N-1];
        int id = 0;
        while(id < sz && fi[id] == ls[id])
        {
            id++;
        }
        if(id != 0)
        {
            string res = fi.substr(0,id);
            return res;
        }
        return "-1";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
