//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBits(int n,int p)
    {
        return ((n&(1 << p)) != 0);
    }
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int>res;
        
        int xs = 0;
        for(int i=0;i<nums.size();i++)
        {
            xs ^= nums[i];
        }
        int t = xs;
        int p = 0;
        int n = 0;
        
        while(n != 1)
        {
            if(xs & 1)
            {
                n = 1;
            }
            xs = xs >> 1;
            p++;
        }
        int t2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(setBits(nums[i],p-1))
            {
                t2 ^= nums[i];
            }
        }
        int sd = t2^t;
        if(sd > t2)
        {
            res.push_back(t2);
            res.push_back(sd);
        }
        else
        {
            res.push_back(sd);
            res.push_back(t2);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
