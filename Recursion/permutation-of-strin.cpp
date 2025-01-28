//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string>res;
    set<string>st;
    void backTrack(int idx,int n,string s)
    {
        if(idx == n)
        {
            if(st.find(s) == st.end()){
                res.push_back(s);
                st.insert(s);
            }
            return;
        }
        for(int i=idx;i<n;i++)
        {
            swap(s[idx],s[i]);
            backTrack(idx+1,n,s);
            swap(s[idx],s[i]);
        }
        
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        int n = s.size();
        backTrack(0,n,s);
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
