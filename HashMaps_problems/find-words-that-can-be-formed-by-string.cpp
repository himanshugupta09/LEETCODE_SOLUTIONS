class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char,int>mp;
        
        for(char c:chars)
        {
            mp[c]++;
        }
        int res = 0;
        
        for(string w:words)
        {
            unordered_map<char,int>wc;
            
            for(char c:w)
            {
                wc[c]++;
            }
            bool ok = true;
            
            for(auto& [c,f]:wc)
            {
                if(mp[c] < f)
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                res += w.size();
            }
        }
        return res;
    }
};
