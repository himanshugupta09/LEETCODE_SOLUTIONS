//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n = arr.size();
        vector<int>res;
        stack<int>stk;
        stk.push(-1);
        for(int i=0;i<n;i++)
        {
            while(stk.top() != -1 && arr[i] >= arr[stk.top()])
            {
                stk.pop();
            }
            res.push_back(i-stk.top());
            stk.push(i);
        }
        return res;
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
