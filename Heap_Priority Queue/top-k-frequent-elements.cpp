class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        vector<int>res;

        priority_queue<pair<int,int>>pq;

        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }

        while(res.size() < k)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
