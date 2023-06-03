//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        
        int sm1 = accumulate(S1.begin(),S1.end(),0);
        int sm2 = accumulate(S2.begin(),S2.end(),0);
        int sm3 = accumulate(S3.begin(),S3.end(),0);
        if(sm1 == sm2 && sm2 == sm3)
        {
            return sm1;
        }
        int min_sum = min(min(sm1,sm2),sm3);
        
        int i=0,j=0,k = 0;
        int n1 = S1.size();
        int n2 = S2.size();
        int n3 = S3.size();
        while(i <= n1 && j <= n2 && k <= n3)
        {
            if(sm1>min_sum)
            {
                sm1 -= S1[i++];
            }
            if(sm2>min_sum)
            {
                sm2 -= S2[j++];
            }
            if(sm3>min_sum)
            {
                sm3 -= S3[k++];
            }
            
            if(sm1 == sm2 && sm2 == sm3)
            {
                return sm1;
            }
            
            min_sum = min(sm1,min(sm2,sm3));
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
