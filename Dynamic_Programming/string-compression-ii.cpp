int dp[101][27][101][101];

class Solution {
public:
    string str;
    
    int  getMin(int i,int prev,int ln,int k)
    {
        
        if(k<0) return INT_MAX;
        if(i >=  str.size()) return 0;
        
        if(dp[i][prev][ln][k] != -1)
        {
            return dp[i][prev][ln][k];
            
        }
        int not_tak =  getMin(i+1,prev,ln,k-1);
        int tak = 0;
        
        if(str[i]-'a' == prev)
        {
            if(ln == 1 || ln == 9 || ln == 99)
            {
                tak++;
            }
            tak = tak + getMin(i+1,prev,ln+1,k);
        }
        else{
            tak = 1 + getMin(i+1,str[i]-'a',1,k);
            }
        dp[i][prev][ln][k] = min(tak,not_tak);
        
        return dp[i][prev][ln][k];
        
        
        
        
        
    }
    
    
    int getLengthOfOptimalCompression(string s, int k) {
       
        
        str = s;
        
        memset(dp,-1,sizeof(dp));
        
        return getMin(0,26,0,k);
        
        
        
        
    }
};
