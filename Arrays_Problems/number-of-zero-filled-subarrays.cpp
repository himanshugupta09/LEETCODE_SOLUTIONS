class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

     long long adder = 0;
    long long temp = 1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] == 0 )
        {
            
            adder += temp;
            temp++;
        }
        else
        {
            temp = 1;
        }
        
    }
    return adder;
    }
};
