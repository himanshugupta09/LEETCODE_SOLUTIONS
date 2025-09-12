class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>tails;
        int max_l = 1;
        for(int num:nums)
        {
            auto lbs = lower_bound(tails.begin(),tails.end(),num);
            if(lbs == tails.end())
            {
                tails.push_back(num);
            }
            else
            {
                *lbs = num;
            }
        }
        return tails.size();
    }
};