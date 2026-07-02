class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
        {
            return "1";
        }
        if(n == 2)
        {
            return "11";
        }
        string res = "11";
        for(int i=3;i<=n;i++)
        {
            string temp;
            res  = res + '&';
            int cnt = 1;
            for(int j=1;j<res.length();j++)
            {
                if(res[j] != res[j-1])
                {
                    temp = temp + to_string(cnt);
                    temp = temp + res[j-1];
                    cnt = 1;
                }
                else
                {
                    cnt++;
                }
            }
            res = temp;

        }
        return res;
    }
};