class Solution {
public:
    int res = 0;
    vector<int>subset;
    
    void doOR(int idx,vector<int>&nums,int n,int maxi)
    {
        if(idx == n)
        {
            int o  = 0;
            for(int i=0;i<subset.size();i++)
            {
                o |= subset[i];
            }
            if(o  == maxi)
            {
                res++;
            }
        }
        else
        {
            subset.push_back(nums[idx]);
            doOR(idx+1,nums,n,maxi);
            subset.pop_back();
            doOR(idx+1,nums,n,maxi);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
       
        int maxi=0;
        for(int i:nums)
        {
            maxi |= i;
        }
        int n=nums.size();
        int idx =  0;
        doOR(idx,nums,n,maxi);
        return res;
        
    }
};
