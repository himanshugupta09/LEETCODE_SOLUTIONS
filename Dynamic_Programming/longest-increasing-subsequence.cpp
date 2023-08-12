//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>tail; // This will store the tails of the increasing subsequences
       tail.push_back(a[0]); // insert 1st element with assumption that it will be part of out LIS
       
       // Ierate from left to right in array
       for(int i=1;i<n;i++)
       {
           // check if current a[i] is greater than last of tails array then add it to our subsequqnce
           if(a[i] > tail.back())
           {
               tail.push_back(a[i]);
           }
           else
           {
               // replace an element in tails (using binary search) to maintain the smallest possible tail.
               auto it = lower_bound(tail.begin(),tail.end(),a[i]);
               *it = a[i];
           }
       }
       return tail.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
