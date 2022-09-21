class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        
        vector<int>res;
        
        int sm = 0;
        
        for(auto i:nums)
        {
            if(i%2 == 0)
            {
                sm += i;
                
            }
        }
        
        
        for(int i=0;i<queries.size();i++)
        {
            int id = queries[i][1];
            int val = queries[i][0];
            
            if(nums[id]%2 == 0)
            {
                sm  -= nums[id];
            }
            nums[id] += val;
            if(nums[id]%2 == 0)
            {
                sm += nums[id];
                
            }
            res.push_back(sm);
        }
        
        return res;
        
        
    }
};
