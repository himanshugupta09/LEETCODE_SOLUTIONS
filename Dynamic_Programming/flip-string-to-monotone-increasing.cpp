class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        

        int num = 0,ans = 0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '0')
            {
                ans = min(ans+1,num);
            }
            else
            {
               num++;
            }
        }

        return ans;
    }
};
