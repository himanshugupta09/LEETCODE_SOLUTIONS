class Solution {
public:

   

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        vector<vector<int>>data;

        for(int i=0;i<ages.size();i++)
        {
            data.push_back({ages[i],scores[i]});
        }

        sort(data.begin(),data.end());

        int final_scores = 0;
        
        vector<int>dp(ages.size());

        for(int i=0;i<ages.size();i++)
        {
           dp[i] = data[i][1];
           final_scores = max(final_scores,dp[i]);

        }


        for(int i=0;i<ages.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(data[i][1] >= data[j][1])
                {
                    dp[i] = max(dp[i],data[i][1] + dp[j]);
                }
            }
            final_scores = max(final_scores,dp[i]);
        }

        return final_scores;

    }
};
