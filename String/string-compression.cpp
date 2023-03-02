class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,res = 0;

        while(i < chars.size())
        {
            int gp = 1;

            while(i+gp < chars.size() && chars[i+gp] == chars[i])
            {
                gp++;
            }
            chars[res++] = chars[i];

            if(gp > 1)
            {
                for(char c: to_string(gp))
                {
                    chars[res++] = c;
                }
            }
            i += gp;
        }
        return res;
    }
};
