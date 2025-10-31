class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool>done(2,false);
        int count = 1;
        int a,b;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1])
            {
                count++;
            }
            if(count == 2 && !done[0])
            {
                a = nums[i];
                count = 1;
                done[0]  = true;
            }
            else if(count == 2 && !done[1])
            {
                b = nums[i];
                done[1] = true;
            }
        }
        return {a,b};
        
    }
};