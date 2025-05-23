class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long>net(n);
        long long res= 0;
        for(int i=0;i<n;i++)
        {
            net[i] = (nums[i]^k) - nums[i];
            res += 1ll*nums[i];
        }
        sort(net.begin(),net.end(),greater<int>());
        //reverse(net.begin(),net.end());
        for(int i=0;i<n;i+=2)
        {
            if(i+1 == n)
            {
                break;
            }
            long long ps = net[i]+net[i+1];
            if(ps > 0)
            {
                res += ps;
            }
        }
        return res;
    }
};