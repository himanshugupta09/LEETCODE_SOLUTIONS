//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        map<char,int>mp;
        int l=0;
        int u = 0;
        for(auto it:str)
        {
            if(it == ' ')
            {
                continue;
            }
            mp[it-'a']++;
            if(mp[it-'a'] == 1)
            {
                u++;
            }
            l++;
        }
        if(l < 26) return false;
        return (u+k) >= 26;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
