class Solution {
public:
    long long distinctNames(vector<string>& ideas) {

     vector<vector<int>>dp(26,vector<int>(26,0));

     unordered_map<string,int>mp;
     for(auto i:ideas)
     {
         mp[i]++;
     }

     long long cnt = 0;

     for(int i=0;i<ideas.size();i++)
     {
         string now = ideas[i];
         char c1 = now[0];

         for(int j=0;j<26;j++)
         {  
             char c2 = j + 'a';
             now[0] = c2;
             if(mp.find(now) == mp.end())
             {
                 dp[c1-'a'][j]++;
             }
         }
     }

     for(int i=0;i<26;i++)
     {
         for(int j=0;j<26;j++)
         {
             cnt += dp[i][j]*dp[j][i];
         }
     }

     return cnt;

    }
};
