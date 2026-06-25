class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stk;
        unordered_map<int,int>mpp;
        vector<int>res;
        for (int i = 0; i < nums2.size(); i++)
        {
            while (!stk.empty() && stk.top() < nums2[i])
            {
                mpp[stk.top()] = nums2[i];
                stk.pop();
            }

            stk.push(nums2[i]);
        }
        while (!stk.empty())
        {
            mpp[stk.top()] = -1;
            stk.pop();
        }
        for(int i=0;i<nums1.size();i++)
        {
            res.push_back(mpp[nums1[i]]);
        }
        return res;
    }
};