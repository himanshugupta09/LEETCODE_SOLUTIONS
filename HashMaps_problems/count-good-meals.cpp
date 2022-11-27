class Solution {
public:
    int countPairs(vector<int>& deliciousness) {

        int mod = 1000000007;
        int n = deliciousness.size();

        long res = 0;

        map<int,int>mp;

        for(auto i:deliciousness)
        {
            int pow = 1;
            for(int j=0;j<22;j++)
            {
                if(mp.find(pow-i) != mp.end())
                {
                    res += mp[pow-i];
                    res %= mod;
                }
                pow*=2;

            }
            mp[i]+=1;

        }

        

        return (int)res;

    }
};
