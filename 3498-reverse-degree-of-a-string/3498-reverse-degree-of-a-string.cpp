class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        for(int i=0;i<s.size();i++)
        {
            int revIdx = 26-(s[i]-'a');
            res += (revIdx*(i+1));
        }
        return res;
    }
};