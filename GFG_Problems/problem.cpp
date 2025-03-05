//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int solve(int i,vector<string>& words, map<string,int> &mp,vector<int> &dp){
        
        string s = words[i];
        
        // if(s.length()==1)
        //  return dp[i]=1;
        
        if(dp[i]!=-1) return dp[i];
        
        int res=1;
        for(int j=0;j<s.length();j++){
           string sn = s.substr(0, j) + s.substr(j + 1);
           if(mp.find(sn)!=mp.end()){
            //   cout<<sn<<endl;
               int ind = mp[sn];
               res = max(res,1 + solve(ind,words,mp,dp));
           }
        }
        
        return dp[i] = res;
    }
    int longestStringChain(vector<string>& words) {
        int n=words.size();
        map<string,int> mp;
         vector<int> dp(n,-1);
        
         std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });
    
        for(int i=0;i<words.size();i++){
            mp[words[i]]=i;
        }
        
        int res=1;
        
    
         for(int i=0;i<words.size();i++){
            res=max(res,solve(i,words,mp,dp));
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
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
