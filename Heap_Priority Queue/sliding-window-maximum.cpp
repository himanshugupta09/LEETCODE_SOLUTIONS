class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int>res(n-k+1);

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }

        res[0] = pq.top().first;

        for(int i=k;i<n;i++)
        {
            while(!pq.empty() && pq.top().second <= (i-k))
            {
                pq.pop();
            }
            pq.push({nums[i],i});
            res[i-k+1] = pq.top().first;

        }
        return res;


       
    }
};
