class Solution {
public:
    vector<vector<int>>memo;
    int md = 1e9+7;

    long totalWays(int up,int ud)
    {
        if(up == 0 && ud == 0)
        {
            return 1;
        }
        if(up < 0 || ud < 0 || ud < up)
        {
            return 0;
        }
        if(memo[up][ud] != 0)
        {
            return memo[up][ud];
        }
        long res = 0;

        res += up*totalWays(up-1,ud);
        res %= md;
        res += (ud-up)*totalWays(up,ud-1);

        res %= md;

        return memo[up][ud] = res;

    }
    int countOrders(int n) {

        memo = vector<vector<int>>(n+1,vector<int>(n+1,0));

        return totalWays(n,n);
    }
};
