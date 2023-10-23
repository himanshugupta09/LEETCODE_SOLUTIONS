class Solution {
public:
    bool isPowerOfFour(int n) {
        int res = 0;
        long long int num = n;
        if(num && !(num&(num-1)))
        {
            while(num > 1)
            {
                num >>= 1;
                res++;
            }
            return res%2 == 0 ? 1 : 0;
        }
        return 0;
    }
};
