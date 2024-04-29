class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int arr = 0;
        
        for(auto i:nums)
        {
            arr ^= i;
        }
        
        int res = 0;
        
        while(k||arr)
        {
            if((arr%2) != (k%2))
            {
                res++;
            }
            k /= 2;
            arr /= 2;
        }
        return res;
    }
};
