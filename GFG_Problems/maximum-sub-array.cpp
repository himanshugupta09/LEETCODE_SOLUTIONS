//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    int i=0,j=0,l=0,r=0;
	    int sum=0,mxm=0;
	    
	    while(j<=n)
	    {
	        if(j==n || a[j]<0)
	        {
	            if(mxm<sum)
	            {
	                mxm=sum;
	                l=i;
	                r=j-1;
	            }
	            
	            i=j+1;
	            sum=0;
	            j++;
	        }
	        else{
	            sum+=a[j];
	            j++;
	        }
	    }
	    
	    if(l == r && a[l]<0) return {-1};
	    vector<int>res(a+l,a+r+1);
	    
	    return res;
	    
	    
	    
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
