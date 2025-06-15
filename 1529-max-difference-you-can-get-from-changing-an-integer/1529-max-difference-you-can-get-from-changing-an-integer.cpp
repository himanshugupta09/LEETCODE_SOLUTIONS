class Solution {
public:
    int maxDiff(int num) {
        auto replace = [](string& s,char x,char y){
            for(char& digit:s)
            {
                if(digit == x)
                {
                    digit = y;
                }
            }

        };
        string s = to_string(num);
        string t = to_string(num);
        
        
        for(char dig:s)
        {
            if(dig != '9')
            {
                replace(s,dig,'9');
                break;
            }
        }
        for(int i=0;i<t.size();i++)
        {
            char dig = t[i];
            if(i == 0)
            {
                if(dig !='1')
                {
                    replace(t,dig,'1');
                    break;
                }
            }
            else
            {
                if(dig != '0' && dig != t[0])
                {
                    replace(t,dig,'0');
                    break;
                }
            }
        }
        return stoi(s)-stoi(t);
    }
};