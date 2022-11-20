//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        return inv(arr,0,N-1);
    }
    long long int inv(long long arr[], int l, int r)
    {
        long long int ans=0;
        if(l<r)
        {   int m=l+(r-l)/2;
            ans+=inv(arr,l,m);
            ans+=inv(arr,m+1,r);
            ans+=merge(arr,l,m,r);
        }
        
        return ans;
    }
    long long int merge(long long arr[], int l, int m, int r)
    {   
        int n1=m-l+1,n2=r-m;
        long long left[n1],right[n2];
        for(int i=0;i<n1;i++)
           left[i]=arr[l+i];
        for(int i=0;i<n2;i++)
            right[i]=arr[m+1+i];
        int i=0,j=0,k=0;
        long long int ans=0;
        while(i<n1 && j<n2)
        {
            if(left[i]<=right[j])
            {   arr[k+l]=left[i]; 
                i++;}
            else{
                arr[k+l]=right[j];
                j++;
                ans+=n1-i;
            }
            k++;
        }
        while(i<n1)
        {
            arr[k+l]=left[i];
            k++;
            i++;
        }
        while(j<n2)
        {
            arr[k+l]=right[j];
            k++;
            j++;
        }
        
        return ans;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
