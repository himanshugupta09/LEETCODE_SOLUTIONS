class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        for(int i=n;i<2*n;i++)
        {
            int secondNumber = nums[i] << 10;
            nums[i-n] |= secondNumber;

        }

        int allone = pow(2,10) - 1;

        for(int i=n-1;i>=0;i--)
        {
            int sen = nums[i] >> 10;
            int fis = nums[i] & allone;
            nums[2*i+1] = sen;
            nums[2*i] = fis;

        }

        return nums;
    }
};
