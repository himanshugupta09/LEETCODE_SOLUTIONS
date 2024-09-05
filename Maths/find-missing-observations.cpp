class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sm = 0;
        int m = rolls.size();
        int act = (n+m)*mean;
        for(int i=0;i<rolls.size();i++)
        {
            sm += rolls[i];
        }
        vector<int>res;
        int left = act-sm;
        while(n)
        {
            int a = left/n;
            if(a > 6)
            {
                return {};
            }
            if(a <= 0)
            {
                return {};
            }
            res.push_back(a);
            left -= a;
            n--;
        }
        return res;
    }
};
