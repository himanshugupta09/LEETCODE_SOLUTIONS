class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char,int>mp;
        int evec = 0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;

            if(mp[s[i]]%2 == 0)
            {
                evec++;
            }
        }

        if(evec*2 == s.size()) return evec*2;
        
        if(evec*2 < s.size()) return evec*2+1;
        
        return evec;

        
    }
}; 
