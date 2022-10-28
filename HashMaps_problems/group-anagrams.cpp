class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
               
        vector<vector<string>>res;
        
        
        map<array<int,26>,vector<string>>mp;
        
        for(string s:strs)
        {
            array<int,26>hash = {0};
            
            for(char i:s)
            {
                hash[i-'a']++;
            }
            
            
            mp[hash].push_back(s);
            
            
        }
        
        
        for(auto[hash,gp]: mp)
        {
            res.push_back(gp);
        }
        return res;
        
        
        
        
    }
};
