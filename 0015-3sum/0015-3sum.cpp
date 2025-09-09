class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n = nums.size();
        for(int i=0;i<n-2;i++)
        {
            int l = i+1;
            int r = n-1;
            if(nums[i] > 0)
            {
                break;
            }
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            while(l < r)
            {
                int sm = nums[i]+nums[l]+nums[r];
                if(sm > 0)
                {
                    r--;
                }
                else if(sm < 0)
                {
                    l++;
                }
                else
                {
                    vector<int>t = {nums[i],nums[l],nums[r]};
                    res.push_back(t);
                    while(l < r && nums[l] == nums[l+1])
                    {
                        l++;
                    }
                    while(l < r && nums[r] == nums[r-1])
                    {
                        r--;
                    }
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};