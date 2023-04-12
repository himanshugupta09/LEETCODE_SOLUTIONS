//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        int mid = n/2;
        sort(arr.begin(),arr.begin()+mid);
        sort(arr.begin()+mid,arr.end());
        
        int i=0,j = mid;
        int res = 0;
        bool ok = false;
        while(i < mid && j < n)
        {
            if(ok)
            {
               res += (j-mid);
            }
            if(arr[i] >= 5*arr[j])
            {
                res++;
                j++;
                ok = false;
            }
            else
            {
                i++;
                ok = true;
            }
        }
        if(j >= n)
        {
            res += (mid-i-1)*(mid);
        }
        return res;

    
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends
