/*
// Approach with sorting only
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] <= nums[i-1])
            {
                int ic = nums[i-1]+1-nums[i];
                res += (ic);
                nums[i] = nums[i-1]+1;
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int res = 0;
        
        vector<int>b(n+maxi+1,0);
        for(auto i:nums)
        {
            b[i]++;
        }
        
        for(int i=0;i<b.size();i++)
        {
            if(b[i] <= 1) continue;
            int d = b[i]-1;
            b[i+1] += d;
            b[i] = 1;
            res += d;
            
        }
        return res;
            
    }
};
