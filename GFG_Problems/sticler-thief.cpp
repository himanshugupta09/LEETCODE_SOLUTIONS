//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        
        
        vector<int>includ(n,0);
        vector<int>exclude(n,0);
        int sm = 0;
        
        includ[0] = arr[0];
        exclude[0] = 0;
        
        
        
        
        int n_inc;
        int n_ex;
        
        for(int i=1;i<=n-1;i++)
        {
            n_inc = exclude[i-1]+arr[i];
            n_ex = max(includ[i-1],exclude[i-1]);
            
            includ[i] = n_inc;
            exclude[i] = n_ex;
            
        }
        
        return max(includ[n-1],exclude[n-1]);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
