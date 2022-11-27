class Solution {
public:
    
    bool isPalindrome(string& str)
    {
        int i=0,j = str.size()-1;
        
        while(i<j)
        {
            if(str[i++] != str[j--])
            {
                return false;
            }
        }
        return true;
        
        
        
    }
    
    
    
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>>ans;
        
        
        if(words.size()<2)
        {
            return ans;
            
        }
        
        unordered_map<string,int>mp;
        
        
        for(int i=0;i<words.size();++i)
        {
            string o = words[i];
            reverse(o.begin(),o.end());
            
            mp[o] = i;
            
            
        }
        
        
        for(int i=0;i<words.size();++i)
        {
            for(int j=0;j<=words[i].size();++j)
            {
                
                string preff = words[i].substr(0,j);
                string suff = words[i].substr(j);
                
                
                if(mp.count(preff) && isPalindrome(suff) && mp[preff] != i)
                {
                    ans.push_back({i,mp[preff]});
                    
                }
                
                if(!(preff.empty()) &&  mp.count(suff) && isPalindrome(preff) && mp[suff] != i)
                {
                    ans.push_back({mp[suff],i});
                    
                }
                
                
            }
        }
        return ans;
        
        
        
        
        
        
    }
};
