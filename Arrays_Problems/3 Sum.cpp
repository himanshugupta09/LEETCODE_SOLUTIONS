class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>res;
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        for(int i=0;i<n-2;i++)
        {
            int l = i+1;
            int j = n-1;
            
            if(nums[i]>0)
                break;
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            
            
            while(l<j)
            {
                int sm = nums[i] + nums[l] + nums[j];
                
                if(sm > 0)
                {
                    j -= 1;
                    
                }
                else if(sm < 0)
                {
                    l++;
                    
                }
                else{
                    vector<int>temp;
                    
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[j]);
                    
                    res.push_back(temp);
                    
                    while(l < j && nums[l] == nums[l+1])
                    {
                        l++;
                    }
                    
                    while(l < j && nums[j-1] == nums[j])
                    {
                        j--;
                        
                    }
                    
                    l++;
                    j--;
                    
                    
                    
                    
                }
            }
        }
        
        return res;
        
        
        
    }
};
