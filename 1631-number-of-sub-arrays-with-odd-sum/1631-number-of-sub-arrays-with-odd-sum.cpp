class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res =  0;
        int odds=0;
        for(int i=0;i<n;i++)
        {
            arr[i] %= 2;
        }
        vector<int>dpOdds(n),dpEve(n);
        dpEve[n-1] = arr[n-1] == 1 ? 0 : 1;
        dpOdds[n-1] = arr[n-1] == 1 ? 1 : 0;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i] == 1)
            {
                dpOdds[i] = (1+dpEve[i+1])%mod;
                dpEve[i] = dpOdds[i+1];
            }
            else
            {
                dpEve[i] =  (1+dpEve[i+1])%mod;
                dpOdds[i] = dpOdds[i+1];
            }
        }
        for(auto oddse:dpOdds)
        {
            res += oddse;
            res %= mod;
        }
        return res;

    }
};