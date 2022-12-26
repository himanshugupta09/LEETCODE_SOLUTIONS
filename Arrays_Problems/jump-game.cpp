class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int i=1;
        int n = nums.size();
        int jmps = nums[0];

        if(jmps == 0 && n != 1)
        {
            return false;
        }

        if(n == 1)
        {
            return true;
        }

        while(i<n)
        {
            jmps--;
            jmps = max(jmps,nums[i]);
            if(jmps == 0 && i != n-1)
            {
                return false;
            }
            i++;
            
        }
        return true;
    }
};
