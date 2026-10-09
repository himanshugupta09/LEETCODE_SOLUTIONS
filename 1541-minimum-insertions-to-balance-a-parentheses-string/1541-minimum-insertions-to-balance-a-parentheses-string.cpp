class Solution {
public:
    int minInsertions(string s) {
        string tf;

        int b_count = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                tf += 'A';
            } else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    tf += 'B';
                    i++;  
                } else {
                    tf += 'B';
                    res++; 
                }
            }
        }
        //cout << tf;
        stack<char>stk;
        for(auto c:tf)
        {
            if(c == 'A')
            {
                stk.push(c);
            }
            else
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
                else
                {
                    res++;
                }
            }
        }
        return res+2*stk.size();
    }
};