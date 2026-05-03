class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if (n != goal.length()) return false;

        int dfa[101][26] = {0};
        dfa[0][s[0] - 'a'] = 1;

        int x = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++)
                dfa[i][j] = dfa[x][j];
            int c = s[i] - 'a';
            dfa[i][c] = i + 1;
            x = dfa[x][c];
        }

        int state = 0;
        for (int i = 0; i < n << 1; i++) {
            state = dfa[state][goal[i % n] - 'a'];
            if (state == n)
                return true;
        }

        return false;
    }
};
