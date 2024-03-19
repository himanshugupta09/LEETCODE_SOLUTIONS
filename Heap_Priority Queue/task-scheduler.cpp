class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        
        for(auto i:tasks)
        {
            mp[i]++;
        }
        priority_queue<int>pq;
        
        for(auto i:mp)
        {
            pq.push(i.second);
        }
        int res = 0;
        
        while(!pq.empty())
        {
            int cy = n+1;
            vector<int>v;
            int tsk = 0;
            
            while(cy-- && !pq.empty())
            {
                if(pq.top() > 1)
                {
                    v.push_back(pq.top()-1);
                }
                pq.pop();
                tsk++;
            }
            for(auto i:v)
            {
                pq.push(i);
            }
            res += (pq.empty() ?  tsk : n+1);
        }
        return res;
        
    }
};
