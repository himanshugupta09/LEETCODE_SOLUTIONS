class Solution {
public:
    bool doesAliceWin(string s) {
        set<char>vows = {'a','e','i','o','u'};
        int vc = 0;
        for(auto i:s)
        {
            if(vows.find(i) != vows.end())
            {
                vc++;
            }
        }
        if(vc%2)
        {
            return true;
        }
        if(vc ==  0)
        {
            return false;
        }
        return true;
    }
};