class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]].push_back(i);
        }
        for(int i=0;i<nums.size();i++)
        {
            int d = target-nums[i];
            if(d == nums[i] && mpp[d].size() > 1)
            {
                return {mpp[d][0],mpp[d][1]};
            }
            else if(d != nums[i] && (mpp.find(d) != mpp.end()))
            {
                int x = mpp[nums[i]][0];
                int y = mpp[d][0];
                if(x <= y)
                {
                    return {x,y};
                }
                return {y,x};
            }
        }
        return {-1};
    }
};