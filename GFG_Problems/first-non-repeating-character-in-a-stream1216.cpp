//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char>q;
		    unordered_map<char,int>mp;
		
		    string res;
		    
		    for(auto i:A)
		    {
		        mp[i]++;
		        if(mp[i] == 1)
		        {
		            q.push(i);
		        }
		        
		        while(!q.empty() && mp[q.front()] > 1)
		        {
		            q.pop();
		        }
		        q.empty() ? res += '#' : res += q.front();
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
