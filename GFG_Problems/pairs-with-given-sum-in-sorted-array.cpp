//{ Driver Code Starts
#include <bits/stdc++.h>


using namespace std;




// } Driver Code Ends

class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
        int res = 0;
        int st = 0,en = n-1;
        
        while(st < en)
        {
            if((arr[st] + arr[en]) == sum)
            {
                st++;
                en--;
                res++;
            }
            else if(arr[st] + arr[en] < sum)
            {
                st++;
            }
            else{
                en--;
                
            }
        }
        if(res)
        {
            return res;
            
        }
        else{
            return -1;
            
        }
    
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int sum;
        cin>>sum;
        Solution obj;
        cout << obj.Countpair(arr, n, sum) << endl;
        
    }
	return 0;
}

// } Driver Code Ends
