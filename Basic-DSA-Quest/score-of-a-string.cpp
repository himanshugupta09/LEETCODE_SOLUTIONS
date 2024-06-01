class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        for(int i=1;i<s.size();i++)
        {
            res += abs((s[i-1]-'a')-(s[i]-'a'));
        }
        return res;
        
    }
};
