class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        vector<int>res;
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                int s = a[i]+b[j];
                if(pq.size() == k && s < pq.top()) break;
                pq.push(s);
                if(pq.size() > k) pq.pop();
            }
        }
        
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
