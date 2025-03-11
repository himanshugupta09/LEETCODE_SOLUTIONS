class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0,b = 0,c = 0;
        int n = s.size();
        int left = 0,right = 0;
    int res = 0;
        while(right < n)
        {
            if(s[right] == 'a')
            {
                a++;
            }
            if(s[right] == 'b')
            {
                b++;
            }
            if(s[right]=='c')
            {
                c++;
            }
            while(a&&(b&&c))
            {
                res += n-right;
                if(s[left] ==  'a')
                {
                    a--;
                    left++;
                }
                else if(s[left] == 'b')
                {
                    b--;
                    left++;
                }
                else
                {
                    c--;
                    left++;
                }
                
            }
            right++;
        }
        return res;
    }
};