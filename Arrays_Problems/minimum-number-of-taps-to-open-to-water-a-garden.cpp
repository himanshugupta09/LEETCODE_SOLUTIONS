class Solution {
public:
    
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int>maxRange(n+1);
        for(int i=0;i<ranges.size();i++)
        {
            int st = max(0,i-ranges[i]);
            int end = min(n,ranges[i]+i);

            maxRange[st] = max(maxRange[st],end);
        }
        int tps = 0;
        int curEn = 0;
        int nxtend = 0;
        
        for(int i=0;i<=n;i++)
        {
            if(i > nxtend)
            {
                return -1;
            }
            if(i > curEn)
            {
                tps++;
                curEn = nxtend;
            }
            nxtend = max(maxRange[i],nxtend);
        }
        return tps;



    }
};
