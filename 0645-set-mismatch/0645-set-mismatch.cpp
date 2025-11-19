class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>res;
        int mis =-1;
        int k = 0,l=0;
        unordered_map<int,int>mpp;
        for(int i:nums)
        {
            mpp[i]++;
            if(l < mpp[i])
            {
                l = mpp[i];
                k = i;
            }
            
        }
        for(int i=1;i<=n;i++)
        {
            if(mpp.find(i) == mpp.end())
            {
                mis = i;
                break;            
            }
        }
        return {k,mis};

        
    }
};