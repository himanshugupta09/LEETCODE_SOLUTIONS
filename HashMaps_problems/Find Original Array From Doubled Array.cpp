class Solution {
public:
    
    
    /* 
    First we take a map, then we sort the given array changed.

   We keep removing the smallest element n and 2 * n and keep putting n into the answer until    changed array becomes empty.

   If at anytime the we are unable to remove elements we return empty array.
   */
    
    
    
    
    
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>res;
        
        if(changed.size()%2 == 1)
        {
            return {};
            
        }
         sort(changed.begin(),changed.end());
        
       unordered_map<int,int>verif;
        
        for(int i=0;i<changed.size();i++)
        {
            verif[changed[i]]++;
        }
        
        for(int i=0;i<changed.size();i++)
        {
            if(verif[changed[i]] == 0) continue;
            
            if(verif[changed[i]*2] == 0)
            {
                return {};
            }
            res.push_back(changed[i]);
            verif[changed[i]]--;
            verif[changed[i]*2]--;
            
            
            
        }
        
        
        
        return res;
               
        
    }
};
