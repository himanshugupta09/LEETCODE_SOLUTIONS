
 ============ RECURSIVE APPROACH=================================================

class Solution {
public:
    int n;
    int solve(int curL,int pase)
    {
        if(curL == n)
        {
            return 0;
        }
        if(curL > n)
        {
            return 1000;
        }
        int opt1 = 2+solve(curL*2,curL);
        int opt2 = 1+solve(curL+pase,pase);
        return min(opt1,opt2);
    }
    int minSteps(int n) {
        string in = "A";
        this->n = n;
        if(n == 1)
        {
            return 0;
        }
        return 1+solve(1,1);
    }
};

//=================================================================================================================================================
class Solution {
public:
    int n;
    int solve(int cur,int pase,vector<vector<int>>&memo)
    {
        if(cur == n)
        {
            return 0;
        }
        if(cur > n)
        {
            return 1000;
        }
        if(memo[cur][pase] != -1)
        {
            return memo[cur][pase];
        }
        int op1 = 2+solve(cur*2,cur,memo);
        int op2 = 1+solve(cur+pase,pase,memo);
        memo[cur][pase] = min(op1,op2);
        return memo[cur][pase];
    }
    int minSteps(int n) {
        this->n = n;
        if(n ==  1)
        {
            return 0;
        }
        //vector<vector<int>>memo((n+1),vector<int>((n/2)+1,-1));
        //return 1+solve(1,1,memo);
        vector<int>dp(n+1,1000);
        dp[1] = 0;
        for(int i=2;i<=n;i++)
        {
            int j = 1;
            while(j <= i/2)
            {
                if(i%j == 0)
                {
                    dp[i] = min(dp[i],dp[j]+i/j);
                }
                j++;
            }
        }
        return dp[n];
    }
};
