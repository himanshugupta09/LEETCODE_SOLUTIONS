//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here4
        vector<int>hash(26,-1);
        string res;
        for(int i=0;i<str.size();i++)
        {
            if(hash[str[i]-'a'] == -1)
            {
                res.push_back(str[i]);
                hash[str[i]-'a']++;
            }
            hash[str[i]-'a']++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends
