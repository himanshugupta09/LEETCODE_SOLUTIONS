class Solution {
public:

    // bool cmp(pair<int,int>pe,pair<int,int>pe2)
    // {
    //     return pe.second > pe2.second;
    // }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int,int>>ap;
        for(int i=0;i<nums1.size();i++)
        {
            ap.push_back({nums2[i],nums1[i]});
        }
        sort(ap.rbegin(),ap.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum = 0;
        for(int i=0;i<k-1;i++)
        {
            pq.push(ap[i].second);
            sum += ap[i].second;

        }
        long long res = 0;

        for(int i=k-1;i<nums1.size();i++)
        {
            
            sum += ap[i].second;
            pq.push(ap[i].second);
            res = max(res,sum*ap[i].first);
            sum -= pq.top();
            pq.pop();
        }

        return res;
        
    }

};
