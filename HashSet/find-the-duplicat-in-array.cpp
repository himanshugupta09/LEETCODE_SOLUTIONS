class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int pre = -1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i == 0)
            {
                pre = nums[i];
            }
            else
            {
                if(nums[i] == pre)
                {
                    break;
                }
                else
                {
                    pre = nums[i];
                }
            }
        }
        return pre;
    }
};
