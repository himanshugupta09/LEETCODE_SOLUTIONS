class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int ans = 1;
        
        int j = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != s[j] + i-j)
            {
                j = i;
                
                
            }
            ans = max(ans,i-j+1);
            
            
        }
        return ans;
        
        
        
    }
};
