class Solution {
public:
    int binary(int n)
    {
        return log2(n)+1;
    }
    int concatenatedBinary(int n) {
        long res = 0,mod = 1e9+7;
        for(int i=1;i<=n;++i)
        {
            int l = binary(i);
            res = ((res << l) % mod + i)%mod;
        }
        return res;
    }
};