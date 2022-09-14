class Solution {
public:
    
   int rev(int n){
        int ans=0;
        while(n>0)
        {
            ans=ans*10;
            ans+=(n%10);
            n=n/10;
        }
        return ans;
    }

    
    int countNicePairs(vector<int>& nums) {
     
        unordered_map<int,int>mp;
        
        long long cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i] - rev(nums[i])) != mp.end())
               {
                   cnt += mp[nums[i] - rev(nums[i])];
                
                   mp[nums[i] - rev(nums[i])]++;
                
               }
            else{
                mp[nums[i] - rev(nums[i])]++;
            }
        }
        
        return cnt%1000000007 ;
        
        
        
    }
};
