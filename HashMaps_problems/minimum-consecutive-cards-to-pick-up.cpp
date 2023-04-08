class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>mp;
        int mini = INT_MAX;
        
        for(int i=0;i<cards.size();i++)
        {
            if(mp.find(cards[i]) == mp.end())
            {
                mp[cards[i]] = i;
            }
            else
            {
                 mini = min(mini,i-mp[cards[i]]+1);
                 mp[cards[i]] = i;
            }
        }
        if(mini != INT_MAX)
        {
            return mini;
        }
        return -1;
        
    }
};
