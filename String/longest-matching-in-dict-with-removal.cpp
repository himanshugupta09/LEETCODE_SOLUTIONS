class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        vector<int> pos[26];

        // Store positions of every character
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }

        string ans = "";

        for (const string &word : d) {
            int current = -1;
            bool possible = true;

            for (char c : word) {
                auto &v = pos[c - 'a'];

                // Find first occurrence strictly after current
                auto it = upper_bound(v.begin(), v.end(), current);

                if (it == v.end()) {
                    possible = false;
                    break;
                }

                current = *it;
            }

            if (possible) {
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};
