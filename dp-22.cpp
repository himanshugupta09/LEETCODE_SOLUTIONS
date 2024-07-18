//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int maxLen = 1;
        int local = 1;
        int  n = arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i] > arr[i-1])
            {
               local=maxLen+1; 
            }
            else if(arr[i] < arr[i-1])
            {
                maxLen=local+1;
            }
            
        }
        return max(maxLen,local);
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
