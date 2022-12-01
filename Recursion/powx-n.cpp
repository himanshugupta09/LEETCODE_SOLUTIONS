class Solution {
public:
    double myPow(double x, int n) {
        long long d = n;
        double ans = 1.0;

        if(d < 0) d = -1*d;

        while(d)
        {
            if(d%2)
            {
                ans *= x;
                d--;

            }
            else
            {
                x = x*x;
                d = d/2;

            }
        }

        if(n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};
