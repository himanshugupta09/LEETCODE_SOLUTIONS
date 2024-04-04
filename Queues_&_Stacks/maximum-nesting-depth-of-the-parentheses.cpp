class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int mx = INT_MIN;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                st.pop();
            }
            int n = st.size();
            mx = max(mx,n);
        }
        return mx;
        
    }
};
