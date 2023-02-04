class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int>pattern(26,0);
        vector<int>text(26,0);


        for(auto i:s1)
        {
            pattern[i-'a']++;
        }

        int i=0;
        int j = 0;

        while(j < s2.size())
        {
            text[s2[j]-'a']++;
            if(j-i+1 == s1.size())
            {
                if(text == pattern)
                {
                    return true;
                }
            }

            if(j-i+1 < s1.size())
            {
                j++;

            }
            else
            {
                text[s2[i]-'a']--;
                i++;
                j++;
                       
            }
        }

        return false;

        
    }
};
