//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long int>res;
        
        long long int xr = Arr[0];
        
        for(int i=1;i<N;i++)
        {
            xr^=Arr[i];
        }
        
        long long int msk = xr & (~(xr-1));
        
        long long int n1=0,n2=0;
        
        for(int i=0;i<N;i++)
        {
            if((Arr[i]&msk) != 0)
            {
                n1 = n1^Arr[i];
            }
            else{
                n2 = n2^Arr[i];
            }
        }
        
        res.push_back(n1);
        res.push_back(n2);
        
        sort(res.begin(),res.end(),greater<long long int>());
        
        
        
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
