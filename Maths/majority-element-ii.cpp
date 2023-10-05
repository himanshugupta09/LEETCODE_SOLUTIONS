class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int lm = floor(n/3);

        if(n < 2)
        {
            return nums;
        }
        if(n == 2 && nums[0] != nums[1])
        {
            return nums;
        }
        vector<int>res;
        int ele = -1;
        int cnt = 0;

        sort(nums.begin(),nums.end());
        ele = nums[0];
        cnt = 1;
        for(int i=1;i<n;i++)
        {
           if(nums[i] == ele)
            {
                cnt++;
                continue;
            }
            else
            {
                if(cnt > lm && ele != nums[i])
                {
                    res.push_back(ele);
                }
                cnt = 1;
                ele = nums[i];
            }

            
        }
        if(cnt > lm)
        {
            res.push_back(ele);
        }
        return res;

    }
};
