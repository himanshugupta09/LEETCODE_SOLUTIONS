class Solution {
public:
    vector<vector<int>>res;
    set<vector<int>>hashed;
    void backTracking(vector<int>&nums,vector<int>&arr,int idx,int target)
    {
        if(target == 0 && (hashed.find(arr) == hashed.end()))
        {
            hashed.insert(arr);
            res.push_back(arr);
            return;
        }
        
        if(idx == nums.size() || target < 0)
        {
            return;
        }
        arr.push_back(nums[idx]);
        backTracking(nums,arr,idx,target-nums[idx]);
        arr.pop_back();
        backTracking(nums,arr,idx+1,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>arr;


        for(int i=0;i<candidates.size();i++)
        {
            backTracking(candidates,arr,i,target);
        }
        return res;
    }
};