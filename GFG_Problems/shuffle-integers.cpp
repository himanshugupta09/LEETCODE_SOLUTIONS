//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    int i = (n/2)-1;
	    
	    for(int j=n-1;j>=(n/2);j--)
	    {
	        arr[j] <<= 10;
	        arr[j] |= arr[i];
	        i--;
	    }
	    i = 0;
	    for(int j=n/2;j<n;j++)
	    {
	        int n1 = arr[j]&1023;
	        int n2 = arr[j] >> 10;
	        arr[i] = n1;
	        arr[i+1] = n2;
	        i += 2;
	        
	    }
	    
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
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
