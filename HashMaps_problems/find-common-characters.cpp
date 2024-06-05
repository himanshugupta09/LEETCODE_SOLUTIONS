class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        
        vector<int> commons(26), curs(26);
        vector<string> res;
        
        // Count occurrences of characters in the first word
        for (char& c : words[0]) {
            commons[c - 'a']++;
        }
        
        // Iterate over the remaining words
        for (int i = 1; i < n; i++) {
            fill(curs.begin(), curs.end(), 0);
            
            // Count occurrences of characters in the current word
            for (char& ch : words[i]) {
                curs[ch - 'a']++;
            }
            
            // Update common character counts
            for (int l = 0; l < 26; l++) {
                commons[l] = min(commons[l], curs[l]);
            }
        }
        
        // Form result from common character counts
        for (int l = 0; l < 26; l++) {
            for (int i = 0; i < commons[l]; i++) {
                res.push_back(string(1, l + 'a'));
            }
        }
        
        return res;
    }
};
