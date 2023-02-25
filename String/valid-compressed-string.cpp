//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int i = 0;
        int j = 0;
        
        while(i < S.size() && j < T.size()){
            if(S[i] == T[j]){
                i++;
                j++;
            }
            else if(isdigit(T[j])){
                string deletedCount = "";
                while(j < T.size() && isdigit(T[j])){
                    deletedCount.push_back(T[j]);
                    j++;
                }
                
                i += stoi(deletedCount);
            }
            else{
                return 0;
            }
        }
        
        if(i == S.size() && j == T.size())
            return 1;
            
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
