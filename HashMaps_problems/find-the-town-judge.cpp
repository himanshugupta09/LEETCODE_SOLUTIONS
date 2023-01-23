class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        //int n = trust.size();
        
        if(trust.size() == 0 && n == 1)
        {
            return 1;

        }

        vector<int>counter(n+1);

        for(auto per:trust)
        {
            counter[per[0]]--;
            counter[per[1]]++;

        }

        for(int ok = 0;ok<counter.size();ok++)
        {
            if(counter[ok] == n-1)
            {
                return ok;
            }

        }
        return -1;

    }
};
