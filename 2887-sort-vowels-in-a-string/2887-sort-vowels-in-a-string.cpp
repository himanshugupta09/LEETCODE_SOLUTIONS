class Solution {
public:
    string sortVowels(string s) {
        set<char>vow = {'A','E','I','O','U','a','e','i','o','u'};
        string vowels;
        for(char c:s)
        {
            if(vow.find(c) != vow.end())
            {
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(),vowels.end());
        string res;
        int j = 0;
        for(char c:s)
        {
            if(vow.find(c) != vow.end())
            {
                res.push_back(vowels[j++]);
            }
            else
            {
                res.push_back(c);
            }
        }
        return res;
    }
};