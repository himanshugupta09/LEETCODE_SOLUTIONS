class Solution {
    /* 

    Algorithm To Solve The Problem

    1. Find the largest index k such that nums[k] < nums[k + 1]. 
            If no such index exists, just reverse nums and  done.
    2. Find the largest index l > k such that nums[k] < nums[l].
    3. Swap nums[k] and nums[l].
    4. Reverse the sub-array nums[k + 1:].

    */
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int k,l;

        for(k = n-2;k>=0;k--)
        {
            if(nums[k] < nums[k+1])
            {
                break;
            }

        }

        if(k < 0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        else
        {
            for(l = n-1;l>k;l--)
            {
                if(nums[l] > nums[k])
                {
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin() + k + 1,nums.end());

        }
    }
};
