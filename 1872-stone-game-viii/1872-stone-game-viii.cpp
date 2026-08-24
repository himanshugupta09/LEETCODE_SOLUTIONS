class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        if(n <= 1)
        {
            return 0;
        }
        vector<int>prefixSum(n+1,0);
        prefixSum[0] = stones[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1]+stones[i];
           // cout << prefixSum[i-1] <<" " << prefixSum[i] << "\n";
        }
        int dp = prefixSum[n-1];
        for(int i=n-2;i>=1;i--)
        {
            dp = max(prefixSum[i]-dp,dp);
        }
        return dp;

    }
};