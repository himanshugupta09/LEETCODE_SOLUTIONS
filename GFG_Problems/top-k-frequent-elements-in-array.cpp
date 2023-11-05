//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        nums.erase(nums.begin(),nums.end());
        priority_queue<pair<int,int>>pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        
        while(k--)
        {
            nums.push_back(pq.top().second);
            pq.pop();
        }
        
        return nums;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
