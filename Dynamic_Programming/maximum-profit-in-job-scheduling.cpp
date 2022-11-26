class Solution {
public:
    
    struct Job{
        int start;
        int finish;
        int profit;
    };

    static bool comp(Job a,Job b)
    {
        return a.finish < b.finish;
    }




    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        
        int n = profit.size();

        Job jobs[n];


        

        for(int i=0;i<n;i++)
        {
            jobs[i].start = startTime[i];
            jobs[i].finish = endTime[i];
            jobs[i].profit = profit[i];
        }
        
        sort(jobs,jobs+n,comp);

        vector<int>dp(n+1,0);
        dp[0] = jobs[0].profit;


        for(int i=1;i<n;i++)
        {
            int including = jobs[i].profit;
            int lninc = -1;

            for(int j=i-1;j>=0;j--)
            {
                if(jobs[j].finish <= jobs[i].start)
                {
                    lninc = j;
                    break;

                }

            }
            if(lninc != -1)
            {
                including += dp[lninc];
            }
            dp[i] = max(including,dp[i-1]);


        }

        return dp[n-1];






    }
};
