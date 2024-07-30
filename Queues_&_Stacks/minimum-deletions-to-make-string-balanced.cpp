class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>stk;
        int res = 0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else
            {
                if(stk.top() == 'b' && s[i] == 'a')
                {
                    res++;
                    stk.pop();
                }
                else
                {
                    stk.push(s[i]);
                }
            }
        }
        return res;
    }
};
