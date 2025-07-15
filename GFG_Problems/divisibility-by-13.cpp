class Solution {
  public:
    long long getNum(string &s)
    {
        long long res;
        int i = s.size()-1;
        res = s[i]-'0';
        long long p = 10;
        while(i >= 0)
        {
            res += p*(s[i]-'0');
            i--;
            p *= 10;
        }
        return res;
    }
    bool divby13(string &s) {
        // code here
        int rem = 0;
        for(char c:s)
        {
            rem = (rem*10+(c-'0'))%13;
        }
        return rem == 0;
    }
};
