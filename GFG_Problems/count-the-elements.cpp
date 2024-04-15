//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // int findIndex(vector<int>&b,int ele,int n)
    // {
    //     int start = 0;
    //     int end = n - 1;

    //     while (start <= end) {
    //         int mid = (start + end) / 2;
    //         // If K is 
    //         if (b[mid] == ele)
    //             return mid-1;
    //         else if (b[mid] < ele)
    //             start = mid + 1;
    //         else
    //             end = mid - 1;
    //     }
    //     // Return insert position
    //     return end + 1;
    // }
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        int mxa = *max_element(b.begin(),b.end());
        int mxb = *max_element(a.begin(),a.end());
        int mx = max(mxa,mxb);
        vector<int>hash(mx+1,0);
        for(int i=0;i<n;i++)
        {
            hash[b[i]]++;
        }
        vector<int>res;
        for(int i=1;i<hash.size();i++)
        {
            hash[i] += hash[i-1];
        }
        for(int i=0;i<query.size();i++)
        {
            int idx = a[query[i]];
            int cnt = hash[idx];
            res.push_back(cnt);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
