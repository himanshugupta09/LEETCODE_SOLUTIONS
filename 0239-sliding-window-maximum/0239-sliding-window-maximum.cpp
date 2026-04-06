class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mst;
        int left = 0, right = 0;

        for (right = 0; right < k; right++) {
            mst.insert(nums[right]);
        }

        vector<int> res;
        res.push_back(*mst.rbegin());

        for (right = k; right < nums.size(); right++) {
            mst.erase(mst.find(nums[left])); // fix here
            left++;
            mst.insert(nums[right]);
            res.push_back(*mst.rbegin());
        }

        return res;
    }
};