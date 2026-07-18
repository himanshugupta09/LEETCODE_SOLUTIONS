class Solution {
public:
    long long getGCD(long long a,long long b)
    {
        if (!a || !b)
        return a | b;
        unsigned shift = __builtin_ctz(a | b);
        a >>= __builtin_ctz(a);
        do {
            b >>= __builtin_ctz(b);
            if (a > b)
                swap(a, b);
            b -= a;
        } while (b);
        return a << shift;
    }
    long long gcdSum(vector<int>& nums) {
        long long runMax = INT_MIN;
        long long res = 0;
        long long prefixGCD = nums[0];
        vector<long long>arr;
        for(auto num:nums)
        {
            runMax = max(runMax,(long long)num);
            prefixGCD = getGCD(runMax,(long long)num);
            arr.push_back(prefixGCD);
        }
        sort(arr.begin(),arr.end());
        int i=0,j = arr.size()-1;
        while(i < arr.size()/2)
        {
            long long gc = getGCD(arr[i],arr[j]);
            res += gc;
            i += 1;
            j -= 1;
        }
        return res;

    }
};