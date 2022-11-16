//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int calBeauty(vector<int>hash)
    {
        int mx = INT_MIN,mn = INT_MAX;
        
        for(auto i:hash)
        {
            if(i == 0){
                continue;
            }
            mx = max(mx,i);
            mn = min(mn,i);
        }
        
        return mx-mn;
    }
    
    int beautySum(string s) {
        // Your code goes here
        int res = 0;
        
        for(int i=0;i<s.size();i++)
        {
            vector<int>hash(26,0);
            
            for(int j=i;j<s.length();j++)
            {
                hash[s[j]-'a']++;
                res += calBeauty(hash);
            }
        }
        
        return res;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
