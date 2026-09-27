class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int>index(n,-1);
        stack<int>stk;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                stk.push(i);
            }
            else if(s[i] == ')')
            {
                int tp = stk.top();
                stk.pop();
                index[tp] = i;
                index[i] = tp;
            }
        }
        string res;
        int dir = 1;
        int i=0;
        while(i < n)
        {
            if(s[i] != ')' && s[i] != '(')
            {
                res += s[i];
                i += dir;
            }
            else
            {
                i = index[i];
                dir *= -1;
                i += dir;
            }
        }
        return res;
    }
};