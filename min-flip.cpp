class Solution {
  public:
    int minFlips(string &s) {
        // code here
        int cnt1 = 0,cnt2 = 0;
        char c = '0';
        
        for(char ch:s)
        {
            if(c == ch)
            {
                cnt2++;
            }
            else
            {
                cnt1++;
            }
            c = (c=='0' ? '1' : '0');
        }
        return min(cnt1,cnt2);
    }
};