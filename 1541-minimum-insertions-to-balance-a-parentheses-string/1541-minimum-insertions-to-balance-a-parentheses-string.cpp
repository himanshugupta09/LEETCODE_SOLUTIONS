class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int open = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                open++;
            }
            else
            {
                if(i+1 < s.size() && s[i+1]==')')
                {
                    i++;
                }
                else
                {
                    res++;
                }
                if(open > 0)
                {
                    open--;
                }
                else
                {
                    res++;
                }
            }
        }
        return res + 2*open;
    }
};