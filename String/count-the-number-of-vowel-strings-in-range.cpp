class Solution {
public:
    bool isVowel(string s)
    {
        set<char>vow = {'a','e','i','o','u'};
        
        if((vow.find(s[0]) != vow.end()) &&(vow.find(s[s.size()-1]) != vow.end()))
           {
               return true;
           }
           else
           {
               return false;
           }
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        
        int cnt = 0;
        for(int i=left;i<=right;i++)
        {
            if(isVowel(words[i]))
            {
                cnt++;
            }
        }
        return cnt;
        
    }
};
