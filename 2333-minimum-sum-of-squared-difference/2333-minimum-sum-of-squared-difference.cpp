class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long>diff;
        long long k = (long long)k1 + k2;
        long long maxDiff = 0;
        long long total = 0;

        long long normal = 0;
        for(int i=0;i<nums1.size();i++)
        {
            long long d = abs(nums1[i]-nums2[i]);
            maxDiff = max(maxDiff,d);
            total += d;
            diff.push_back(d);
            normal += pow(d,2);
        }
        if(k1 == 0 && k2 == 0)
        {
            return normal;
        }
        if(k >= total){
            return 0;
        }
        long long lo = 0,hi = maxDiff;

        while(lo < hi)
        {
            long long mid = lo+(hi-lo)/2;
            long long need = 0;

            for(long long d:diff)
            {
                if(d > mid)
                {
                    need += d-mid;
                }
            }
            if(need <= k)
            {
                hi = mid;
            }
            else
            {
                lo = mid+1;
            }
        }
        long long x = lo;
        long long used = 0;
        long long res = 0;

        for(long long d:diff)
        {
            if(d > x)
            {
                used  += d-x;
                d = x;
            }
            res += d*d;
        }
        long long rem = k-used;
        res -= rem*(2*x-1);

        return res;

    }
};