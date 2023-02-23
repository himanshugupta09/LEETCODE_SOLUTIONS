class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();

        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.emplace_back(capital[i],profits[i]);
        }

        sort(v.begin(),v.end());

        priority_queue<int>pq;
        int i=0;

        for(int j=0;j<k;j++)
        {
            while(i < n && v[i].first <= w)
            {
                pq.push(v[i++].second);
            }
            if(pq.empty())
            {
                break;
            }
            w += pq.top();
            pq.pop();
        }

        return w;



        
    }
};
