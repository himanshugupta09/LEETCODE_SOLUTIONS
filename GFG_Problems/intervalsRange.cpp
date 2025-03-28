//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1] < b[1];
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<vector<int>>merged;
        for(int i=0;i<n;i++)
        {
            merged.push_back({start[i],finish[i]});
        }
        sort(merged.begin(),merged.end(),cmp);
        int res = 1;
        int last = merged[0][1];
        for(int i=1;i<n;i++)
        {
            if(merged[i][0] > last)
            {
                res+=1;
                last = merged[i][1];
            }
            //last = merged[i][1];
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
