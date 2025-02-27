class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        unordered_map<int,int>vals;
        
        for(int i=0;i<n;i++)
        {
            vals[arr[i]] = i;
            for(int j=0;j<i;j++)
            {
                int dif = arr[i]-arr[j];
                int prev = (vals.find(dif) != vals.end()) ? vals[dif] : -1;

                if(dif < arr[j] && prev >= 0)
                {
                    dp[j][i] = dp[prev][j]+1;
                }
                else
                {
                    dp[j][i] = 2;
                }
                maxLen = max(maxLen,dp[j][i]);
            }
        }
        return maxLen > 2  ? maxLen : 0;
    }
};