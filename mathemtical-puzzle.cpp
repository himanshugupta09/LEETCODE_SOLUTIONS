class Solution {
  public:
    int findMax(int n) {
        // code Here
        if (n < 10)
            return n;

        int p = 1;

        while (p * 10 <= n)
            p *= 10;

        int candidate = (n / p - 1) * p + (p - 1);

        auto digitSum = [](int x) {
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };

        if (digitSum(n) >= digitSum(candidate))
            return n;

        return candidate;
    }
};
