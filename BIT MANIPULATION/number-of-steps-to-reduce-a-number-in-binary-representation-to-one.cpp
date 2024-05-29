class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        int n = s.size();
        int car = 0;
        for(int i=n-1;i>=1;i--)
        {
            int dig = s[i]-'0' + car;
            if(dig&1)
            {
                car = 1;
                res += 2;
            }
            else
            {
                res++;
            }
        }
        return res+car;
        
    }
};
