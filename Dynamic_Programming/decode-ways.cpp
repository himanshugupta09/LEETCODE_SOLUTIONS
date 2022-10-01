class Solution {
public:
    vector<int>dp;
    
    int decoder(int n,string s)
    {
        if(n>=s.size()) return 1;
        else if(s[n] == '0') return 0;
        else if(n == s.size()-1) return 1;
        
        else if(dp[n] != -1) return dp[n];
        
        else if(s[n] == '1' || (s[n] == '2' && (s[n+1] >= 48 && s[n+1] <= 54)))
        {
            return dp[n] = decoder(n+1,s) + decoder(n+2,s);
        }
        else return dp[n] = decoder(n+1,s);
        
        
    }
    
    
    int numDecodings(string s) {
       dp.resize(s.size());
       dp.assign(s.size(),-1);
        
       return decoder(0,s);
        
        
    }
};
