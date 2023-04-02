class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(),potions.end());
        vector<int>res;
        int m = potions.size();
        int maxPos = potions[m-1];

        for(int i=0;i<spells.size();i++)
        {
            long long minPos = ceil((1.0*success)/spells[i]);
            if(minPos > maxPos)
            {
                res.push_back(0);
                continue;
            }
            else
            {
                auto idx = lower_bound(potions.begin(),potions.end(),minPos) - potions.begin();
                
                res.push_back(m-idx);
            }

        }
        return res;
    }
};
