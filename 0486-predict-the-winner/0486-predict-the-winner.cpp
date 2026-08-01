class Solution {
public:
    int maxDiff(int left,int right,vector<int> &nums)
    {
        if(left == right)
        {
            return nums[left];
        }
        int scoreL = nums[left]-maxDiff(left+1,right,nums);
        int scoreR = nums[right] - maxDiff(left,right-1,nums);

        return max(scoreL,scoreR);
    }
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();

        if(n%2 == 0)
        {
            return true;
        }
        return maxDiff(0,n-1,nums) >= 0;

        
    }
};