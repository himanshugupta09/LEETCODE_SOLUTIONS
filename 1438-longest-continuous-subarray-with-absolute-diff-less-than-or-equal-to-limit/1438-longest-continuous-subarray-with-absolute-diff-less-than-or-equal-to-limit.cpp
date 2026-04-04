class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> maxD; // stores values in decreasing order
        deque<int> minD; // stores values in increasing order

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Maintain max deque
            while (!maxD.empty() && nums[right] > maxD.back()) {
                maxD.pop_back();
            }
            maxD.push_back(nums[right]);

            // Maintain min deque
            while (!minD.empty() && nums[right] < minD.back()) {
                minD.pop_back();
            }
            minD.push_back(nums[right]);

            // Shrink window if invalid
            while (maxD.front() - minD.front() > limit) {
                if (nums[left] == maxD.front()) maxD.pop_front();
                if (nums[left] == minD.front()) minD.pop_front();
                left++;
            }

            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};