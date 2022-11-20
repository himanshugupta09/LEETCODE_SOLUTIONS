class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        
        long long close = INT_MAX;
        
        
       
	    
	    for(int i=0;i<n-2;i++)
	    {
	        int j = i+1;
	        int k = n-1;
	        
	        while(j <  k)
	        {
	           long long  curSum = nums[i] + nums[j] + nums[k];
                
                if(curSum == target){
                    return curSum;
                }
                
                if(abs(curSum - target) < abs(close - target))
                {
                    close = curSum;
                }
                if(curSum < target)
                {
                    j++;
                }
                else{
                    k--;
                }
                
                
	        }
	    }
        
        return close;
       
       
    }
};
