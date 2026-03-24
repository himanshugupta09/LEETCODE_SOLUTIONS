class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto num:nums)
        {
            mpp[num]++;
        }
        priority_queue<pair<int,int>>maxHeap;
        for(auto i:mpp)
        {
            maxHeap.push({i.second,i.first});
        }
        vector<int>res;
        while(k--)
        {
            pair<int,int>pr = maxHeap.top();
            maxHeap.pop();
            res.push_back(pr.second);
        }
        return res;
    }
};