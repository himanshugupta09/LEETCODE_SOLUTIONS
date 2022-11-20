class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int Int = 0;
        
        for(int i = s.size()-1;i>=0;i--)
        {
            if(i != 0 && m[s[i-1]] < m[s[i]])
            {
                Int += (m[s[i]] - m[s[i-1]]);
                i--;
                continue;
            }
            Int += (m[s[i]]);
        }
        
        return Int;
    }
};
