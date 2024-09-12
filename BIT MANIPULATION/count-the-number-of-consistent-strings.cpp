class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int alow = 0;
        
        for(int i=0;i<allowed.size();i++)
        {
            alow |= 1 << (allowed[i]-'a');
        }
        int res = 0;
        
        for(string& word:words)
        {
            bool ok =  true;
            
            for(int i=0;i<word.length();i++)
            {
                int bit = (alow >> (word[i]-'a'))&1;
                if(bit == 0)
                {
                    ok = false;
                    break;
                }
                
            }
            if(ok)
            {
                res++;
            }
        }
        return res;
    }
};
