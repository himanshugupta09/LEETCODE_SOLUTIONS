//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int l=0,h=n-1,md;
        
        if(n==1)
        {
            return arr[0];
        }
        
        while(l<=h)
        {
            md = (l+h)/2;
            
            if(md&1 && arr[md] == arr[md-1])
            {
                l = md+1;
            }
            else if(md&1 && arr[md-1] != arr[md])
            {
                h = md-1;
            }
            else{
                if(md != n-1 && arr[md] == arr[md+1])
                {
                    l = md+1;
                }
                else{
                    h = md-1;
                    
                }
            }
        }
        
        return arr[l];
        
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
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends
