class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq;

        for(auto i:nums)
        {
            pq.push(i);
        }
        long long score = 0;

        while(k--)
        {
            long long n = pq.top();
            score += n;
            pq.pop();
            n = ceil(n/3.0);
            pq.push(n);
        }
        return score;

        
    }
};
