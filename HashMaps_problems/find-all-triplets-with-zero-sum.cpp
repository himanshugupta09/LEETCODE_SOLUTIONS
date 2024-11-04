//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<vector<int>>res;
        
        for(int i=1;i<arr.size()-1;i++)
        {
            for(int k=i+1;k<arr.size();k++)
            {
                int sm = -1*(arr[i]+arr[k]);
                for(int j:mp[sm])
                {
                    if(j<i) res.push_back({j,i,k});
                }
            }
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
