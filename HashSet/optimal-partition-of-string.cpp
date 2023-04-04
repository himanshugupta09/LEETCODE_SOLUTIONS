class Solution {
public:
    int partitionString(string s) {
        
       
        int cnt = 1;
        set<char>h;
        for(int i=0;i<s.size();i++)
        {
            
            if(h.find(s[i]) != h.end())
            {
                cnt++;
                h.erase(h.begin(),h.end());
                h.insert(s[i]);
            }
            else
            {
                h.insert(s[i]);
            }
            
        }
        return cnt;
    }
};
