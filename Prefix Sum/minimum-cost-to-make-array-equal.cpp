class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
        vector<pair<long long , long long>>ns;

        for(int i=0;i<nums.size();i++)
        {
            ns.push_back({(long long)nums[i],(long long)cost[i]});
        }
        sort(ns.begin(),ns.end());

        vector<long long>prefix(n,0);

        prefix[0] = ns[0].second;

        for(int i=1;i<n;i++)
        {
            prefix[i] = ns[i].second + prefix[i-1];

        }

        long long res = 0;

        for(int i=1;i<n;i++)
        {
            res += ns[i].second*(ns[i].first - ns[0].first);
        }
        long long ans = res;

        for(int i=1;i<n;i++)
        {
            long long gp = ns[i].first - ns[i-1].first;
            res += prefix[i-1]*gp;

            res -= gp*(prefix[n-1] - prefix[i-1]);
            ans = min(ans,res);
        }

        return ans;


    }
};
