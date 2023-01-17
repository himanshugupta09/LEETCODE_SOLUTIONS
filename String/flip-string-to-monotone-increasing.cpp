class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int m = count(s.begin(),s.end(),'0');

        int ans = m;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '0')
            {
                m--;
                ans = min(ans,m);
            }
            else
            {
                m++;
            }
        }
        return ans;
    }
};
