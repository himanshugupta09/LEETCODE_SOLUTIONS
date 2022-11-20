class Solution {
public:
    
    int nB(int n) {
		  return log2(n) + 1;
    }
    
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9 + 7;
        
        for (int i = 1; i <= n; ++i) {
            int l = nB(i);
            ans = ((ans << l) % mod + i) % mod;
        }
        return ans;
    }
};
