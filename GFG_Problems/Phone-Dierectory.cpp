//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>>result;
        
        unordered_map<string,set<string>>mp;
        
        for(int i=0;i<n;i++)
        {
            string S;
            
            for(int j=0;j<contact[i].size();j++)
            {
                S.push_back(contact[i][j]);
                mp[S].insert(contact[i]);
                
            }
        }
        
        string temp;
        
        for(int i=0;i<s.size();i++)
        {
            temp.push_back(s[i]);
            
            if(mp.find(temp) == mp.end())
            {
                result.push_back({"0"});
                
            }
            else{
                result.push_back(vector<string>(mp[temp].begin(),mp[temp].end()));
                
            }
            
        }
        return result;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
