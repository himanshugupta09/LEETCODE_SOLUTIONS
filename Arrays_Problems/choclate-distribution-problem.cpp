//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    // firstly sort the given array in non decreasing order
    sort(a.begin(),a.end());
    // intitalize a variable to store result with Maximum value
    long long minimumChoclates = INT_MAX;
    // Now set to pointers say low and high low will be at 0 index and high will point to n-1
    // and iterate while low <= high 
    long long low = 0,high = n-1;
      
    
    for(int i=0;i<=n-m;i++)
    {
        minimumChoclates = min(minimumChoclates,a[i+m-1]-a[i]);
    }
    return minimumChoclates;
    
    
    
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends
