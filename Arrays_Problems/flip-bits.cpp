//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    
    int getMaximumSumSubArray(int a[],int n)
    {
        int tsum = 0;
        int fins = 0;
        
        for(int i=0;i<n;i++)
        {
            tsum += a[i];
            fins = max(fins,tsum);
            
            if(tsum < 0)
            {
                tsum = 0;
            }
        }
        return fins;
    }
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i])
            {
                a[i] = -1;
                cnt++;
            }
            else
            {
                a[i] = 1;
            }
        }
        int maxSum = getMaximumSumSubArray(a,n);
        return cnt+maxSum;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends
