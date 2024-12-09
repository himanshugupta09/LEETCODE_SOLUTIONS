//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  static bool cmp(vector<int>&a,vector<int>&b)
  {
      return a[0] < b[0];
  }
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        
        // code here
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        
        vector<vector<int>>res;
        int i =0;
        int j = 1;
        int n =  intervals.size();
        
        while(i  < n)
        {
            int init = intervals[i][0];
            int fins  = intervals[i][1];
            
            while(j < n && fins >= intervals[j][0])
            {
                fins = max(fins,intervals[j][1]);
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
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
