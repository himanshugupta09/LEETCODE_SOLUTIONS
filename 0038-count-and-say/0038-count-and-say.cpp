class Solution {
public:
     string makeCounter(string &st) {
        string res;
        int n = st.size();
        
        for (int i = 0; i < n; ) {
            char currentChar = st[i];
            int count = 0;
            
            // Count the number of consecutive characters
            while (i < n && st[i] == currentChar) {
                count++;
                i++;
            }
            
            // Append the count and the character to the result
            res += to_string(count) + currentChar;
        }
        
        return res;
    }
    string countAndSay(int n) {
        string cur = "1";  // Start with the base case

        for (int i = 2; i <= n; i++) {
            cur = makeCounter(cur);  // Generate the next sequence
        }

        return cur;
    }
};
