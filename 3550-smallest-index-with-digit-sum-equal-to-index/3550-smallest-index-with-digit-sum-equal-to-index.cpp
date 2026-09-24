class Solution {
public:
    int digSum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum += num%10;
            num /= 10;
        }
        return sum;

    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int smallestIdx = n;
        for(int i=0;i<n;i++)
        {
            int sum = digSum(nums[i]);
            if(i == sum)
            {
                smallestIdx = min(smallestIdx,i);
            }
        }
        return smallestIdx == n ? -1 : smallestIdx;
    }
};