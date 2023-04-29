typedef long long ll;
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        ll res = 1;
        
        vector<pair<int,int>>vp;
        
        for(int i=0;i<nums.size();i++)
        {
            vp.push_back({nums[i],i});
        }
        
        sort(vp.begin(),vp.end());
        int j = 2;
        
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(vp[i].second > vp[i+1].second)
            {
                res += j;
            }
            else
            {
                res += 1;
            }
            j++;
        }
        return res;
        
    }
};
