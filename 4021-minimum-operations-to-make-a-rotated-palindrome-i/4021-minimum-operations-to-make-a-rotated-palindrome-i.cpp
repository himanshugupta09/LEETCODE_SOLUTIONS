class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;

        // Try every possible left rotation
        for (int shift = 0; shift < n; shift++) {
            int cost = shift;

            for (int i = 0; i < n / 2; i++) {
                // Character at position i after rotation
                char a = s[(i + shift) % n];

                // Character at mirrored position after rotation
                char b = s[(n - 1 - i + shift) % n];

                int diff = abs(a - b);

                // Cyclic alphabet distance
                cost += min(diff, 26 - diff);
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};