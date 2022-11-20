class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>includ(n,0);
        vector<int>exclude(n,0);
        int sm = 0;
        
        includ[0] = nums[0];
        exclude[0] = 0;
        
        
        
        
        int n_inc;
        int n_ex;
        
        for(int i=1;i<=nums.size()-1;i++)
        {
            n_inc = exclude[i-1]+nums[i];
            n_ex = max(includ[i-1],exclude[i-1]);
            
            includ[i] = n_inc;
            exclude[i] = n_ex;
            
        }
        
        return max(includ[n-1],exclude[n-1]);
        
        
        
        
    }
};
