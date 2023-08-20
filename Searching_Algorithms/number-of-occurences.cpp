//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int solve(int l,int h,int arr[],int n,int x){
        if(l > h){
            return 0;
         }
        int mid=l+(h-l)/2;
        if(arr[mid] == x){
            return 1+solve(l,mid-1,arr,n,x)+solve(mid+1,h,arr,n,x);
        }
        else if(arr[mid] > x){
            return solve(l,mid-1,arr,n,x);
        }
        else{
            return solve(mid+1,h,arr,n,x);
        }
    }
 
    int count(int arr[], int n, int x) {
        return solve(0,n-1,arr,n,x);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
