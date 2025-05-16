class Solution {
public:
    bool isValid(string &a,string &b)
    {
        int dis = 0;
        if(a.size() != b.size())
        {
            return false;
        }
        for(int i=0;i<a.size();i++)
        {
            if(a[i] != b[i])
            {
                dis++;
            }
            
        }
        return dis == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {

        int n= groups.size();
        vector<int>dp(n,1);
        vector<int>pre(n,-1);

        int maxI = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isValid(words[i],words[j]) == 1 && dp[j]+1 > dp[i] && groups[i] != groups[j])
                {
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                }
            }
            if(dp[i] > dp[maxI])
            {
                maxI = i;
            }
        }

        vector<string>res;
        for(int i=maxI;i>=0;i = pre[i])
        {
            res.emplace_back(words[i]);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};