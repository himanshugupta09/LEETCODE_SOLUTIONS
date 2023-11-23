class Solution {
public:
    bool chk(vector<int>& arr)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        unordered_set<int>ars;
        
        for(int num:arr)
        {
            mini = min(mini,num);
            maxi = max(maxi,num);
            ars.insert(num);
        }
        
        if((maxi-mini)%(arr.size()-1) != 0)
        {
            return false;
        }
        int dif = (maxi-mini)/(arr.size()-1);
        int cur = mini+dif;
        
        while(cur  < maxi)
        {
            if(ars.find(cur) == ars.end())
            {
                return false;
            }
            cur += dif;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = l.size();
        vector<bool>res;
        
        for(int i=0;i<l.size();i++)
        {
            vector<int>tem(begin(nums) + l[i],begin(nums) + r[i] + 1);
            res.push_back(chk(tem));
        }
        return res;
    }
};
