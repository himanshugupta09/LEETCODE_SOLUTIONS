//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        int i=0;
        int j = arr.size()-1;
        sort(arr.begin(),arr.end());
        vector<int>res;
        int trn = 0;
        while(i <= j)
        {
            if(trn%2 == 0)
            {
                res.push_back(arr[j]);
                j--;
            }
            else
            {
                res.push_back(arr[i]);
                i++;
            }
            trn++;
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
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
