class Solution {
public:
    int maxProduct(vector<int>& nums) {
     
       int ans = INT_MIN;
        int temp = 1;
        
        
        
        
        for(int i=0;i<nums.size();i++)
        {
            temp*=nums[i];
            ans = max(ans,temp);
            
            
            if(temp == 0)
            {
                temp = 1;
                
            }
                
        }
        
        
        temp = 1;
        
        for(int j=nums.size()-1;j>=0;j--)
        {
            temp*=nums[j];
            ans = max(ans,temp);
            
            
            if(temp == 0)
            {
                temp = 1;
                
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
    }
};
