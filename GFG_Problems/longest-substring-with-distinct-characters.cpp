//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int left = 0;
        vector<int>cnt(26,0);
        int maxL=1;
        int n = s.size();
        for(int right = 0;right<n;right++)
        {
            int cid = s[right]-'a';
            if(cnt[cid] != 0)
            {
                left = max(left,cnt[cid]);
            }
            cnt[cid]=right+1;
            maxL=max(maxL,right-left+1);
        }
        return maxL;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
