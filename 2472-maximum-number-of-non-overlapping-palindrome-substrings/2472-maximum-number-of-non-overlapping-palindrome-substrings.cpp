class Solution {
public:
    int maxPalindromes(std::string s, int k) {
        std::string T = "^#";
        for (char c : s) {
            T += c;
            T += '#';
        }
        T += '$';
        
        int n = T.length();
        std::vector<int> P(n, 0);
        
        int center = 0;
        int right_boundary = 0;
        
        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * center - i;
            
            if (i < right_boundary) {
                P[i] = std::min(right_boundary - i, P[mirror]);
            }
            
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                P[i]++;
            }
            
            if (i + P[i] > right_boundary) {
                center = i;
                right_boundary = i + P[i];
            }
        }
        
        int count = 0;
        int last_idx = -1;
        
        for (int i = 0; i < s.length(); ++i) {
            int start_k = i - k + 1;
            if (start_k > last_idx) {
                int center_k = start_k + i + 2;
                if (P[center_k] >= k) {
                    count++;
                    last_idx = i;
                    continue;
                }
            }
            
            int start_k1 = i - (k + 1) + 1;
            if (start_k1 > last_idx) {
                int center_k1 = start_k1 + i + 2;
                if (P[center_k1] >= k + 1) {
                    count++;
                    last_idx = i;
                }
            }
        }
        return count;
    }
};