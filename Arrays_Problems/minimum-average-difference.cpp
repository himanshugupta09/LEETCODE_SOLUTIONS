class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int sm = 0;
        long long int cur_sum = 0;
        int n = nums.size();
        for(auto i:nums)
        {
            sm += i;
        }
        long long int mini = INT_MAX;
        long long int ans = 0;

        for(int i=0;i<nums.size();i++)
        {
            cur_sum += nums[i];
            int av1 = cur_sum/(i+1);
            if(i == n-1){
                if(av1 < mini)
                {
                    return n-1;
                }
                else
                {
                    break;
                }
            }
            int av2 = (sm-cur_sum)/(n-i-1);

            if(abs(av1-av2) < mini)
            {
                mini = abs(av1-av2);
                ans = i;

            }

        }

        return ans;
    }
};
