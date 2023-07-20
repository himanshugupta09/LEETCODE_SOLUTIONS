//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
      map<char,int>mp;
      for(auto i:S)
      {
          mp[i]++;
      }
      char res = '$';
      int idx = INT_MAX;
      for(int i=0;i<S.size();i++)
      {
          if(mp[S[i]] == 1 && i < idx)
          {
              res = S[i];
              idx = i;
              break;
          }
      }
     return res;
      
      
       
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends
