//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        // sort(numerator,numerator+n);
        // sort(denominator,denominator+n);
        
        unordered_map<double,int>checker;
        
        for(int i=0;i<n;i++)
        {
            double num = numerator[i]*1.0/denominator[i];
            checker[num]++;
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            int val = denominator[i] - numerator[i];
            double res = val*1.0/denominator[i];
            checker[1.0*numerator[i]/denominator[i]]--;
            if(checker.find(res) != checker.end())
            {
                ans += checker[res];
            }
        }
        return ans;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
