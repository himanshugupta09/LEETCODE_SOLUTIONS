class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>dif(n+1,0);
        for(auto q:queries)
        {
            dif[q[0]]++;
            dif[q[1]+1]--;
        }
        int ocs = 0;
        vector<int>ops;
        for(auto i:dif)
        {
            ocs += i;
            ops.push_back(ocs);
        }
        for(int i=0;i<n;i++)
        {
            if(ops[i] < nums[i])
            {
                return false;
            }

        }
        return true;
    }
};