class Solution {
public:

    map<int,int>mp;
    int dp[2001][2001];
    int canJump(vector<int>stones,int N,int index,int prevJump)
    {
        if(index == N-1)
        {
            return true;
        }
        if(dp[index][prevJump] != -1)
        {
            return dp[index][prevJump];
        }
        int res= false;

        for(int next = prevJump-1;next <= prevJump+1;next++)
        {
            if(next > 0 && mp.find(stones[index]+next) != mp.end())
            {
                res = res || canJump(stones,N,mp[stones[index]+next],next);
            }
        }
        return dp[index][prevJump] = res;
    }
    bool canCross(vector<int>& stones) {
        
        int index = 0;
        int prevJump = 0;
        int n = stones.size();

        for(int i=0;i<n;i++)
        {
            mp.insert({stones[i],i});
        }
        memset(dp,-1,sizeof(dp));
        return canJump(stones,n,0,0);
        
    }
};
