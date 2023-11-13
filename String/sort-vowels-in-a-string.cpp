
class Solution {
public:
    bool chk(char c)
    {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    string sortVowels(string s) {
        
        string sortedV = "AEIOUaeiou";
        string res;
        int j = 0;
        
        map<char,int>mp;
        for(char i:s)
        {
            if(chk(i)) mp[i]++;
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(!chk(s[i]))
            {
                res += s[i];
            }
            else
            {
                while(mp[sortedV[j]] == 0)
                {
                    j++;
                }
                res += sortedV[j];
                mp[sortedV[j]]--;
            }
        }
        return res;
    }
};
