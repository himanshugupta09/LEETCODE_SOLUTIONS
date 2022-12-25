class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i++)
        {
            nums[i] = nums[i] + nums[i-1];
        }

        vector<int>res;
        for(int i=0;i<queries.size();i++)
        {
            int x = upper_bound(nums.begin(),nums.end(),queries[i]) - nums.begin();
            res.push_back(x);
        }

        return res;
    }
};
