class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>dummy = nums;

        for(int i=0;i<nums.size();i++){
            dummy[i] = abs(dummy[i]);
        }
        sort(dummy.begin(),dummy.end());
        int i = 0;
        int j = nums.size()-1;
        int  k = 0;
        while(i <= j)
        {
            if(k%2 == 0)
            {
                nums[k] = dummy[j];
                j--;
            }
            else
            {
                nums[k] = dummy[i];
                i++;
            }
            k++;
        }
        long long sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2)
            {
                sum -= (nums[i]*nums[i]);
            }
            else
            {
                sum += (nums[i]*nums[i]);
            }
        }
        return sum;
    }
};