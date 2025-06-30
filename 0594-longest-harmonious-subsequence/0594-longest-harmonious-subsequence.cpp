class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int num:nums)
        {
            mpp[num]++;
        }
        int res = 0;
        for(auto& [num,cnt]:mpp){
            if(mpp.count(num+1))
            {
                int ln = cnt+mpp[num+1];
                res = max(res,ln);
            }
        }
        return res;
    }
};