class Solution {
public:
    int minChanges(string s) {
        
        int res= 0;
        int n = s.size();
        for(int i=0;i<=n-2;i+=2)
        {
            if(s[i] != s[i+1])
            {
                res++;
            }
        }
        return res;
        
    }
};
