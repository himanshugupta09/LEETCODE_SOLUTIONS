//    APPROACH WITH SLIDING WINDOW
        class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        
        int n = s.size();
        int left = 0, right = 0;
        int currCost = 0;
        int maxLen = 0;

        while (right < n) {
            currCost += abs(s[right] - t[right]);
            while (currCost > maxCost) {
                currCost -= abs(s[left] - t[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};

// Blow is appraoch for binary Search with Prefix sum

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> prefix_sum(s.size() + 1, 0);
        for (int len = 1; len <= s.size(); ++len) {
            prefix_sum[len] = prefix_sum[len - 1] + abs(s[len - 1] - t[len - 1]);
        }
        int max_len = 0;
        for (int left = 0; left < s.size(); ++left) {
            const int target_cost = maxCost + prefix_sum[left];
            auto right_it = upper_bound(prefix_sum.begin() + left, prefix_sum.end(), target_cost);
            const int len = right_it - prefix_sum.begin() - left - 1;
            max_len = max(max_len, len);
        }
        return max_len;
        
    }
};
