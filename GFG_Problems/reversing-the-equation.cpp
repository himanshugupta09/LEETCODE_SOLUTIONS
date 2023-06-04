//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
    {
         string st;
         string str;
         for(int i=s.length()-1;i>=-1;i--){
             
             if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||i<0){
                 reverse(st.begin(), st.end());
                 str=str+st;
                 
                 str=str+s[i];
                 st="";
             }
             else
             st=st+s[i];
         }
     return str;   
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
