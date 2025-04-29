class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int j = 0;
        int count = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]  == maxi)
            {
                count++;
            }
            while(count >= k && j <= i)
            {
                res += (n-i);
                
                if(nums[j] == maxi)
                {
                    count--;
                }
                j++;
            }
        }
        return res;
    }
};