class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>&nums,vector<int>arr,vector<bool>&visited)
    {
        if(arr.size() == nums.size())
        {
            res.push_back(arr);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i])
            {
                continue;
            }
            visited[i]=true;
            arr.push_back(nums[i]);
            dfs(nums,arr,visited);
            visited[i] = false;
            arr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>arr;
        vector<bool>vis(nums.size(),false);
        dfs(nums,arr,vis);
        return res;
    }
};