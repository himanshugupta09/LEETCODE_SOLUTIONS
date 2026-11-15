class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int pre = 0;
        int odd = 0,eve = 1;
        int res = 0;

        for(auto i:arr)
        {
            pre += i;
            if(pre%2 == 0)
            {
                res += odd;
                eve++;
            }
            else
            {
                res += eve;
                odd++;
            }
            res %= mod;
        }
        return res;
    }
};