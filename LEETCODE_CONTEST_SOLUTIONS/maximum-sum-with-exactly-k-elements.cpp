class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int>pq;
        
        for(auto i:nums)
        {
            pq.push(i);
        }
        
        int mx = 0;
        
        while(k--)
        {
            mx += pq.top();
            int tp = pq.top();
            pq.pop();
            tp++;
            pq.push(tp);
        }
        
        return mx;
    }
};
