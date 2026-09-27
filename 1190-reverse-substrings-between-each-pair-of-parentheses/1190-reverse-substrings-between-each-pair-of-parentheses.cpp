class Solution {
public:
    string reverseParentheses(string s) {
        string current = "";
        stack<string>stk;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                stk.push(current);
                current = "";
            }
            else if(s[i] == ')')
            {
                reverse(current.begin(),current.end());
                string prev = stk.top();
                stk.pop();
                current = prev + current;
            }
            else
            {
                current += s[i];
            }
        }
        return current;
    }
};