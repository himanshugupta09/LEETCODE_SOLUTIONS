class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        int left = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            maxHeap.push({nums[right], right});
            minHeap.push({nums[right], right});

            // Check if the absolute difference between the maximum and minimum
            // values in the current window exceeds the limit
            while (maxHeap.top().first - minHeap.top().first > limit) {
                // Move the left pointer to the right until the condition is
                // satisfied. This ensures we remove the element causing the
                // violation
                left = min(maxHeap.top().second, minHeap.top().second) + 1;

                // Remove elements from the heaps that are outside the current
                // window
                while (maxHeap.top().second < left) {
                    maxHeap.pop();
                }
                while (minHeap.top().second < left) {
                    minHeap.pop();
                }
            }

            // Update maxLength with the length of the current valid window
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
