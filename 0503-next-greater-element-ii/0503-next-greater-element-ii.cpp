class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>stk;
        vector<int>res(n,-1);
        for(int i=0;i<2*n;i++)
        {
            int idx = i%n;
            while(!stk.empty() && nums[stk.top()] < nums[idx])
            {
                res[stk.top()] = nums[idx];
                stk.pop();
            }
            if(idx < n) stk.push(idx);
        }
        return res;
    }
};