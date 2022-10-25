//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int>res;
        deque<int>q;
        
        int i=0;
        
        while(i<k)
        {
            while(!q.empty() && q.back() < arr[i])
            {
                q.pop_back();
                
            }
            q.push_back(arr[i]);
            i++;
            
        }
        res.push_back(q.front());
        int ok = 0;
        
        while(i < n)
        {
            while(!q.empty() && arr[i] > q.back())
            {
                q.pop_back();
            }
            q.push_back(arr[i]);
            
            if(q.front() == arr[ok])
            {
                q.pop_front();
                
            }
            res.push_back(q.front());
            
            ok++;
            i++;
        }
        
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
