//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    
    bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}
    int minNumber(int arr[],int N)
    {
        int sm = 0;
        int res =0;
        for(int i=0;i<N;i++)
        {
            sm += arr[i];
        }
        if(isPrime(sm))
        {
            return 0;
        }
        else
        {
            
            while(!isPrime(sm))
            {
                sm++;
                res++;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
