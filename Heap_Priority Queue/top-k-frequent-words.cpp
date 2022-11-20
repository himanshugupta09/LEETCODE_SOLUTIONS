class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string,int>mp;
        
        priority_queue<pair<int,string>>pq;
        
        for(auto i:words)
        {
            mp[i]++;
            
        }
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
            
        }
        
        vector<string>res;
        
        for(int i=0;i<mp.size();i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
            
        }
        
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res.size()-1;j++){
                if(res[j] > res[j+1] && mp[res[j]] == mp[res[j+1]]) swap(res[j],res[j+1]);
            }
        }
        
        
        
        vector<string>fin;
        
        for(int i=0;i<k;i++)
        {
            fin.push_back(res[i]);
            
        }
        
        return fin;
        
    }
};
