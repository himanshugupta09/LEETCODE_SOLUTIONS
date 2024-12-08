//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  static bool cmp(vector<int>&a,vector<int>&b)
  {
      return a[0] < b[0];
  }
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>res;
        sort(arr.begin(),arr.end(),cmp);
        int i = 0;
        int j = 1;
        int n = arr.size();
        if(n <= 1) return arr;
        while(i < n)
        {
            int init = arr[i][0];
            int fins = arr[i][1];
            
            while(j < n && arr[j][0] <= fins)
            {
                fins =  max(fins,arr[j][1]);
                j++;
            }
            res.push_back({init,fins});
            i = j;
            
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
