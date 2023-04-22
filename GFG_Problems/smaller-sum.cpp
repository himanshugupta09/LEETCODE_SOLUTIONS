//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        
       vector<int>carr(arr.begin(),arr.end());
       sort(carr.begin(),carr.end());
       
       vector<long long>ps;
       ps.push_back(carr[0]);
       
       for(int i=1;i<n;i++)
       {
           ps.push_back(ps[ps.size()-1] + carr[i]);
       }
       
       vector<long long>res(n,0);
       
       for(int i=0;i<n;i++)
       {
           int idx = lower_bound(carr.begin(),carr.end(),arr[i])-carr.begin();
           
           if(idx != 0)
           {
               res[i] = ps[idx-1];
           }
           
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
