class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)
        {
            return nums;
        }
        multiset<int>window;
        for(int i=0;i<k;i++)
        {
            window.insert(nums[i]);
        }
        vector<int>res;
        res.push_back(*window.rbegin());
        int j = 0;
        for(int i=k;i<nums.size();i++)
        {
            window.erase(window.find(nums[j]));
            j++;
            window.insert(nums[i]);
            res.push_back(*window.rbegin());
        }
        return res;
    }
};