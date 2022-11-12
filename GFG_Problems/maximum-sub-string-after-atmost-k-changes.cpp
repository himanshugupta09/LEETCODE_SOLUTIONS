//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    int res = 0;
		    vector<int>hash(26,0);
		    
		    int left = 0;
		    
		    for(int i=0;i<s.size();i++)
		    {
		        hash[s[i]-'A']++;
		        
		        int mv = i-left+1-*max_element(hash.begin(),hash.end());
		        
		        if(mv>k)
		        {
		           hash[s[left]-'A']--;
		           left++;
		        }
		        else{
		            res = max(res,i-left+1);
		        }
		    }
		    
		    return res;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
