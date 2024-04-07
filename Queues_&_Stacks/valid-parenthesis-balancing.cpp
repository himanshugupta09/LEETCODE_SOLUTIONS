class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st;
        stack<int>as;
        
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            if(ch == '(')
            {
                st.push(i);
            }
            else if(ch == '*')
            {
                as.push(i);
            }
            else if(ch == ')')
            {
                if(!st.empty()){ 
                    st.pop();
                }
                else if(!as.empty()){
                    as.pop();
                }
                else{
                    return false;
                }
            }
            
            
        }
        while(!st.empty() && !as.empty())
        {
            if(st.top() > as.top())
            {
                return false;
            }
            st.pop();
            as.pop();
        }
        return st.empty();
    }
};
