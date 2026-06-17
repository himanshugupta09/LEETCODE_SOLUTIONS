class Solution {
public:
    vector<vector<int>> res;

    void backTracking(vector<int>& nums, vector<int>& arr, int start, int target) {
        if (target == 0) {
            res.push_back(arr);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Since array is sorted, no need to continue further
            if (nums[i] > target)
                break;

            arr.push_back(nums[i]);
            backTracking(nums, arr, i + 1, target - nums[i]); // use once
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> arr;
        backTracking(candidates, arr, 0, target);

        return res;
    }
};