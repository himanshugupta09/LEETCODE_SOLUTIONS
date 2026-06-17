class Solution {
public:
    vector<vector<string>>res;
    bool isValid(string s,int l,int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(string s,int idx,vector<string>&init)
    {
        if(idx == s.size())
        {
            res.push_back(init);
            return;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(isValid(s, idx, i))
            {
                init.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, init);
                init.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>init;

        solve(s,0,init);
        return res;
    }
};