//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        // Your code goes here
        int i=0,j=n-1;
      int res=(j-i-1)*min(height[i],height[j]);
       while(j>i){
           if(height[j]>height[i]){
               i++;
           }
           else  
           j--;
            res=max(res,(j-i-1)*min(height[i],height[j]));
       }
       if(res<0)
       return 0;
       return res;
    }   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
