class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        int xc = 0;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == x)
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count == 0)
            {
                x = nums[i];
                count = 1;
            }
        }
        for(int i:nums)
        {
            if(i == x)
            {
                xc++;
            }
        }
        count = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == x)
            {
                count++;
            }
            int rem = xc-count;
            if(2*count > i+1 && rem*2 > n-i-1)
            {
                return i;
            }
        }
        return -1;

    }
};