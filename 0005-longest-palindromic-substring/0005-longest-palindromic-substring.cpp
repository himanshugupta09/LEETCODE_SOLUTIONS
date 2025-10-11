class Solution {
public:
    string longestPalindrome(string s) {
        int maxL = 0;  // Start with the smallest palindrome length (1)
        int st = 0, en = 0;  // Initialize to the first character's index
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            // For odd-length palindromes (center at i)
            int low = i, high = i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > maxL) {
                    maxL = high - low + 1;
                    st = low;
                    en = high;
                }
                low--;
                high++;
            }
            
            // For even-length palindromes (center between i and i + 1)
            low = i;
            high = i + 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > maxL) {
                    maxL = high - low + 1;
                    st = low;
                    en = high;
                }
                low--;
                high++;
            }
        }
        
        return s.substr(st, en - st + 1);  // Return the longest palindrome substring
    }
};
