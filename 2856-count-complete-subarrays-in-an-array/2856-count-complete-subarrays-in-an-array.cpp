class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>uni(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        int k = uni.size();
        int j = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
            if(mpp[nums[i]] == 1) k--;
            while(k == 0)
            {
                mpp[nums[j]]--;
                if(mpp[nums[j++]] == 0) k++;
            }
            res += j;
        }
        return res;
    }
};