class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>>hp;
        
        for(int i=0;i<nums.size();i++)
        {
            hp.push({nums[i],i});
            
        }
        
        vector<int>ids;
        
        while(k--)
        {
            pair<int,int> t=hp.top();
            ids.push_back(t.second);
            hp.pop();
            
        }
        
        sort(ids.begin(),ids.end());
        
        vector<int>maxSub;
        
         for(int i=0;i<ids.size();i++)
         {
             maxSub.push_back(nums[ids[i]]);
             
         }
        
        return maxSub;
        
        
        
    }
};
