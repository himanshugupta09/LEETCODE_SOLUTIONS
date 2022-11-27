class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();;
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == val)
            {
                cnt++;
                
            }
            else{
                nums[i-cnt] = nums[i];
                
            }
        }
        
        
        
        return n-cnt;
        
        
    }
};
