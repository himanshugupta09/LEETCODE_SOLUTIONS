class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>st;
        for(auto i:s)
        {
            st.insert(i);
        }
        int res = 0;
        for(char ch:st)
        {
            int i=-1;
            int j=0;
            for(int k=0;k<s.size();k++)
            {
                if(s[k] == ch)
                {
                    if(i  == -1)
                    {
                        i=k;
                    }
                    j = k;
                }
                
            }
            unordered_set<char>bet;
            for(int k=i+1;k<j;k++)
            {
                bet.insert(s[k]);
            }
            res += bet.size();
        }
        return res;

    }
};
