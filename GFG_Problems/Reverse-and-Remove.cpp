//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
       int n = S.size();
       int i=0,j=n-1;
       
       vector<int>hash(26,0);
       for(auto i:S)
       {
           hash[i-'a']++;
       }
       vector<int>pos(26,-1);
       bool ok = true;
       
       while(i <= j)
       {
           if(ok)
           {
               int el = S[i]-'a';
               if(hash[el]>1)
               {
                   ok = false;
                   pos[el] = i;
               }
               if(hash[el] == 1)
               {
                   pos[el]=i;
               }
               hash[el]--;
               i++;
               
           }
           else
           {
               int el = S[j]-'a';
               if(hash[el] > 1)
               {
                   ok = true;
               }
               if(hash[el] == 1)
               {
                   pos[el]  = j;
               }
               hash[el]--;
               j--;
           }
       }
       string res = "";
       for(int i=0;i<n;i++)
       {
           int el = S[i]-'a';
           if(pos[el] == i)
           {
               res.push_back(S[i]);
           }
       }
       if(ok == false)
       {
           reverse(res.begin(),res.end());
       }
       return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
