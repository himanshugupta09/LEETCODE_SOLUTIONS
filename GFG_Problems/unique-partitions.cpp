//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>> ans;
        vector<int> list;
        f(n,ans,list);
        return ans;
    }
    
    void f(int n,vector<vector<int>>& ans,vector<int>& list) {
        if(n<=0) {
            if(n==0) {
                vector<int> list1;
                list1.assign(list.begin(),list.end());
                ans.push_back(list1);
            }
            return;
        }
        
        int v=n;
        if(list.size()>0) v = list[list.size()-1];
        
        for(int i=v;i>=1;i--) {
            list.push_back(i);
            f(n-i,ans,list);
            list.pop_back();
        }
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends
