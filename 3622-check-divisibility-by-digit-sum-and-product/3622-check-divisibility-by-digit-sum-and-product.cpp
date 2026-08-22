class Solution {
public:
    int digSum(int n)
    {
        int res = 0;
        while(n != 0)
        {
            res += n%10;
            n /= 10;
        }
        return res;
    }
    int digProd(int n)
    {
        int res = 1;
        while(n != 0)
        {
            res *= n%10;
            n /= 10;
        }
        return res;
    }
    bool checkDivisibility(int n) {
        int sum = digSum(n);
        int pro = digProd(n);
        return n%(sum+pro) == 0;
    }
};