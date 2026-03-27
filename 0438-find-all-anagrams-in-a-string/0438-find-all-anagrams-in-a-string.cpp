class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size()) return res;

        vector<int> mp1(26, 0), mp2(26, 0);

        // Build frequency for p and first window
        for(int i = 0; i < p.size(); i++) {
            mp1[p[i] - 'a']++;
            mp2[s[i] - 'a']++;
        }

        // Count initial matches
        int count = 0;
        for(int i = 0; i < 26; i++) {
            if(mp1[i] == mp2[i]) count++;
        }

        int i = 0;
        for(int j = p.size(); j < s.size(); j++) {
            
            // If all matched
            if(count == 26) res.push_back(i);

            // Add new character
            int idxAdd = s[j] - 'a';
            mp2[idxAdd]++;
            if(mp2[idxAdd] == mp1[idxAdd]) count++;
            else if(mp2[idxAdd] == mp1[idxAdd] + 1) count--;

            // Remove old character
            int idxRemove = s[i] - 'a';
            mp2[idxRemove]--;
            if(mp2[idxRemove] == mp1[idxRemove]) count++;
            else if(mp2[idxRemove] == mp1[idxRemove] - 1) count--;

            i++;
        }

        // Check last window
        if(count == 26) res.push_back(i);

        return res;
    }
};