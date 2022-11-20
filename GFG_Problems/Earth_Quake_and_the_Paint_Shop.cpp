//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        // code here
        
        //map<int,int>mp_int;
        map<string,int>mp_string;
        
        vector<alphanumeric> res;
        
        for(int i=0;i<N;i++)
        {
            mp_string[A[i]]++;
            
        }
        
        for(auto i:mp_string)
        {
            res.push_back({i.first,i.second});
            
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
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u : ans) cout << u.name << " " << u.count << "\n";
    }
}
// } Driver Code Ends
