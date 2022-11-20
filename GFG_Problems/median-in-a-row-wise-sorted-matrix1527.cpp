//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int get_greater(vector<int> &a,int t)
    {
        int i=0,j=a.size()-1;
        
        while(i <= j)
        {
            int m = (i+(j-i)/2);
            
            if(a[m] <= t)
            {
                i = m+1;
            }
            else{
                j = m-1;
            }
        }
        return i;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here     
        
         int low=0;

         int high=1e9;

         while(low<=high){

         int mid=low+(high-low)/2;

          int cnt=0;

            for(int i=0;i<R;i++){  

              cnt+=get_greater(matrix[i],mid);

            }

            if(cnt<=(R*C)/2){

                low=mid+1;

            }else{

                high=mid-1;

            }

        }return low;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends
