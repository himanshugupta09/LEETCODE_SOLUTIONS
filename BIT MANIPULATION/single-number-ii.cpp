class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int a = 0;
        int b = 0;
        
        for (int i = 0; i < nums.size(); i++){
           a = (~b) & (a ^ nums[i]);
           b = (~a) & (b ^ nums[i]);
        }
        return a;
    }
};
