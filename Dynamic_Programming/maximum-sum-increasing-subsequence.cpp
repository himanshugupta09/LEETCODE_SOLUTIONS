//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int res = INT_MIN;
	    vector<int>dp(n);
	    for(int i=0;i<n;i++)
	    {
	        dp[i] = arr[i];
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        //int sm = arr[i];
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i] > arr[j])
	            {
	                dp[i] = max(dp[i],arr[i]+dp[j]);
	            }
	        }
	        res = max(res,dp[i]);
	    }
	    return res;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
