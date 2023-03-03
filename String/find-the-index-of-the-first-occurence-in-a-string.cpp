class Solution {
public:
    int idx = -1;
    int KMP(string text, string pattern)
    {
        int m = text.length();
        int n = pattern.length();
    
        // if pattern is an empty string
        if (n == 0)
        {
            
            return 0;
        }
    
        // if text's length is less than that of pattern's
        if (m < n)
        {
           
            return -1;
        }
    
        // next[i] stores the index of the next best partial match
        int next[n + 1];
    
        for (int i = 0; i < n + 1; i++) {
            next[i] = 0;
        }
    
        for (int i = 1; i < n; i++)
        {
            int j = next[i];
    
            while (j > 0 && pattern[j] != pattern[i]) {
                j = next[j];
            }
    
            if (j > 0 || pattern[j] == pattern[i]) {
                next[i + 1] = j + 1;
            }
        }
    
        for (int i = 0, j = 0; i < m; i++)
        {
            if (text[i] == pattern[j])
            {
                if (++j == n) {
                    idx =  i - j + 1;
                    break;
                }
            }
            else if (j > 0)
            {
                j = next[j];
                i--;    // since `i` will be incremented in the next iteration
            }
        }
        return idx;
}

    int strStr(string haystack, string needle) {
        return KMP(haystack,needle);
    }
};
