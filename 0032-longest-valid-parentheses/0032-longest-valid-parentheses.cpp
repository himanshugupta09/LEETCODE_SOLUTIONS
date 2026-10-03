class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        
        stack<int>st;
        int trash = 0;
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(s[i-1]=='('){
                st.push(i);
            }
            else{
                if(st.empty()){
                    trash= i;
                    continue;
                }
                else{
                    st.pop();
                }
                if(st.empty()){
                    ans= max(ans, (int)(i-trash));
                }
                else{
                    ans= max(ans, (int)(i-st.top()));
                } 
            }
            
        }
        return ans;
    }
};