class Solution {
public:
    vector<vector<int>>res;
   // set<vector<int>>dups;
    
    void makeSubsets(vector<int>&nums,int idx,int n,vector<int>t)
    {
        res.push_back(t);
        for(int i=idx;i<n;i++)
        {
            t.push_back(nums[i]);
            makeSubsets(nums,i+1,n,t);
            t.pop_back();
            
        }
        return;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>t;
        int n = nums.size();
        
        makeSubsets(nums,0,n,t);
        
        return res;
    }
};
