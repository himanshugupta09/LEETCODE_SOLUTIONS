//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int n =  price.size();
            
            int b1 = INT_MIN;
            int s1 = 0;
            int b2 = INT_MIN;
            int s2 = 0;
            
            for(int i=0;i<n;i++)
            {
                b1 = max(b1,-price[i]);
                s1 = max(s1,b1+price[i]);
                b2 = max(b2,s1-price[i]);
                s2 = max(s2,b2+price[i]);
            }
            return s2;
            
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
