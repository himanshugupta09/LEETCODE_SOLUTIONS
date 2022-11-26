class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n = rains.size();
        
        vector<int>res;

        set<int>s;
        map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            if(rains[i] == 0)
            {
                s.insert(i);
                res.push_back(1);

            }
            else
            {
                if(mp.find(rains[i]) != mp.end())
                {
                    auto it = s.lower_bound(mp[rains[i]]);
                    if(it == s.end())
                    {
                        return {};
                    }
                    res[*it] = rains[i];
                    s.erase(*it);
                }
                mp[rains[i]] = i;
                res.push_back(-1);
            }
        }

        return res;


    }
};
