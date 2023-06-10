//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            int a[n];
            int k = 0;
            for(int i=0;i<n;i++)
            {
                if(arr[i] < 0)
                {
                    a[k++] = arr[i];
                }
            }
            
            for(int i=0;i<n;i++)
            {
                if(arr[i] >= 0)
                {
                    a[k++] = arr[i];
                }
            }
            
            for(int i=0;i<n;i++)
            {
                arr[i] = a[i];
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends
