class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> uniqueNums(nums.begin(),unique(nums.begin(), nums.end()));
        int ans = INT_MAX;

        for (int i = 0; i < uniqueNums.size(); ++i) {
            int s = uniqueNums[i];
            int e = s + n - 1;
            auto it = upper_bound(uniqueNums.begin(), uniqueNums.end(), e);

            int idx = distance(uniqueNums.begin(), it);

            ans = min(ans, n - (idx - i));
        }
        return ans;
    }
};
