class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(auto i:nums)
        {
            pq.push(i);
        }
        int res = 0;
        while(pq.top() < k)
        {
            res++;
            pq.pop();
        }
        return res;
        
    }
};
