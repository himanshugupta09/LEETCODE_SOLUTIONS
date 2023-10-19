class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a,b;
        for(auto i:s)
        {
            if(i != '#')
            {
                a.push_back(i);
            }
            else if(a.size() > 0)
            {
                a.pop_back();
            }
        }
        for(auto i:t)
        {
            if(i != '#')
            {
                b.push_back(i);
            }
            else if(b.size() > 0)
            {
                b.pop_back();
            }
        }
        return a == b;
    }
};
