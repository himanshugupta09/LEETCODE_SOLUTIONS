//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    int LSP(string new_string)
    {
        int n = new_string.size();
        int lsp[n];
        lsp[0] = 0;
        int i=1;
        int j=0;
        
        while(i < n)
        {
            if(new_string[i] == new_string[j])
            {
                lsp[i] = j+1;
                i++;
                j++;
            }
            else
            {
                if(j != 0)
                {
                    j = lsp[j-1];
                }
                else
                {
                    lsp[i] = 0;
                    i++;
                }
            }
            
            
        }
        return lsp[n-1];
    }
    
    int addMinChar(string str){    
        //code here
        string rev = str;
        reverse(rev.begin(),rev.end());
        
        string new_string = str + "#" + rev;
        int lsp = LSP(new_string);
        return str.length()-lsp;
        
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
