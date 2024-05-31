class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i:nums)
        {
            x ^= i;
        }
        unsigned int lo  = x & -(unsigned int)x;
        vector<int>res(2,0);
        
        for(int i:nums)
        {
            if((lo&i) == 0){
                res[0] ^= i;
            }else
            {
                res[1] ^= i;
            }
        }
        return res;
    }
};
