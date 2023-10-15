class Solution {
public:
    int md = 1e9+7;
    vector<vector<int>>memo;
    int arrLen;

    int dp(int curr,int rem)
    {
        if(rem == 0)
        {
            if(curr == 0)
            {
                return 1;
            }
            return 0;
        }
        if(memo[curr][rem] != -1)
        {
            return memo[curr][rem];
        }
        int res = dp(curr,rem-1);
        if(curr > 0)
        {
            res = (res+dp(curr-1,rem-1))%md;
        }
        if(curr < arrLen-1)
        {
            res = (res + dp(curr+1,rem-1))%md;
        }
        memo[curr][rem] = res;
        return res;
    }


    int numWays(int steps, int arrLen) {
        arrLen = min(steps,arrLen);
        this->arrLen = arrLen;
        memo = vector(arrLen,vector(steps+1,-1));
        return dp(0,steps);
    }
};
