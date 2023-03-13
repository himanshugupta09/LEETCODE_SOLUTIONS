class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<>());
        long long ans = 0;
        long long cur = 0;
        for(int i=0;i<nums.size();i++)
        {
            cur += nums[i];
            if(cur > 0)
            {
                ans++;
            }
            else
            {
                break;
            }
           
            
        }
        return ans;
        
    }
};
