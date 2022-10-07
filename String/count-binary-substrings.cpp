class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int res  = 0,old = 0,now = 1;
        
        for(int i=1;i<s.size();i++)
        {
            if(s[i-1] != s[i])
            {
                res += min(old,now);
                old = now;
                now = 1;
            }
            else{
                now++;
            }
        }
        
        return res + min(now,old);
        
        
        
    }
};
