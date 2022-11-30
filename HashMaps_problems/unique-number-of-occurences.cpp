class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        set<int>s;
        map<int,int>mp;

        for(auto &i:arr)
        {
            mp[i]++;
        }

        


        for(auto i:mp)
        {
            if(s.find(i.second) != s.end())
            {
                return false;
            }
            s.insert(i.second);
        }
        return true;
    }
};
