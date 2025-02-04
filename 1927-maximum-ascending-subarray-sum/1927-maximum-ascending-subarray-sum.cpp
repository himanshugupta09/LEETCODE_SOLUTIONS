class Solution {
public:
    int maxAsc = 0;

    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int sum = nums[i];
            for(int j=i+1;j<n;j++)
            {
                if(nums[j] > nums[j-1])
                {
                    sum +=  nums[j];
                }
                else
                {
                    break;
                }
            }
            maxAsc = max(maxAsc,sum);
        }
        return maxAsc;
    }
};