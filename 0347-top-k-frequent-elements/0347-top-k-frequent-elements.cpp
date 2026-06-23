class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>bucket(n+1);
        unordered_map<int,int>mpp;
        
        for(int num:nums)
        {
            mpp[num]++;
        }

        for(auto &[num, f] : mpp)
        {
            bucket[f].push_back(num);
        }
        
        vector<int>res;
        for(int i=n;i>=1 && res.size() < k;i--)
        {
            for(int num:bucket[i])
            {
                res.push_back(num);
                if(res.size()== k)
                {
                    break;
                }
            }
        }
        return res;

    }
};