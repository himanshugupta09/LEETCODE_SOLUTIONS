class Solution {
public:
    vector<int>memo;

    int solve(int n)
    {
        if(memo[n] != 0)
        {
            return memo[n];
        }
        int gms = -1;
        for(int i=1;i<=n/2;i++)
        {
            int n1 = i;
            int n2 = n-i;
            int mp1 = max(n1,solve(n1));
            int mp2 = max(n2,solve(n2));

            int mx = mp1*mp2;

            if(mx > gms)
            {
                gms = mx;
            }
        }
        memo[n] = gms;
        return gms;

    }
    int integerBreak(int n) {
        
        memo.resize(n+1,0);
        if(n <= 3)
        {
            return n-1;
        }
        int res = solve(n);
        if(res > n)
        {
            return res;
        }
        return n;
    }
};
