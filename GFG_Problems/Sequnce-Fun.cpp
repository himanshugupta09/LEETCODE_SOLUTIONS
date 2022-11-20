//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
	    int md = 1e9 + 7;
	    
		int NthTerm(int n){
		    long ans = 2;
		    // Code  here
		    for(int i=1;i<n;i++)
		    {
		        ans = (long)(ans*(i+1)%md + 1)%md;
		    }
		    
		    
		    return (int)ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
