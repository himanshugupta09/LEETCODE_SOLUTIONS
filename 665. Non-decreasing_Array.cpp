class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt =0 ;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                if(cnt == 1)
                {
                    return false;
                }
                cnt += 1;
                if(i>=2 && nums[i-2]>nums[i])
                    nums[i] = nums[i-1];
               
            }
        }
         return true;
            
           
        
    }
};
