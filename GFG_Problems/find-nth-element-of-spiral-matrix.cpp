//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
       int findK(int a[MAX][MAX],int n,int m,int k)
    {
 	   int rowbegin=0;
 	   int rowend=n-1;
 	   int colbegin=0;
 	   int colend=m-1;
 	   vector<int>spiral;
 	while(rowbegin<=rowend && colbegin<=colend) {  
 	   //Traverse right
 	   for(int i=colbegin;i<=colend;i++){
 	       spiral.push_back(a[rowbegin][i]);
 	   }
 	   rowbegin++;
 	   
 	  //Traverse down
 	   for(int i=rowbegin;i<=rowend;i++){
 	       spiral.push_back(a[i][colend]);
 	   }
 	   colend--;
 	   
 	   //Traverse left
 	   if(rowbegin<=rowend)
 	   {
 	       for(int i=colend;i>=colbegin;i--){
 	       spiral.push_back(a[rowend][i]);
 	   }
 	   rowend--;
 	   }
 	   
 	   //Traverse up
 	    if(colbegin<=colend)
 	   {
 	       for(int i=rowend;i>=rowbegin;i--){
 	       spiral.push_back(a[i][colbegin]);
 	   }
 	   colbegin++;
 	   }
    }
    return spiral[k-1];
    }


};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
