class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0;
        int b = 0;
        int c = 0;

        int res = 0;

        int left = 0;
        int n = s.size();
        int right = 0;
        while(right < n)
        {
            if(s[right] == 'a')
            {
                a++;
                
            }
            else if(s[right] == 'b')
            {
                b++;
                
            }
            else if(s[right] == 'c')
            {
                c++;
                
            }

            while(a && (b&&c))
            {
                res += n-right;
                if(s[left] == 'a'){
                    a--;
                    left++;
                }
                else if(s[left] == 'b')
                {
                    b--;
                    left++;
                }
                else if(s[left] == 'c')
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