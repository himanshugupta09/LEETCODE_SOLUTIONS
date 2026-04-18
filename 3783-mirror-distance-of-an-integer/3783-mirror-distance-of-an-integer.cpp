class Solution {
public:
    int reverseInt(int n)
    {
        int reverse = 0;
        while(n != 0)
        {
            reverse = reverse*10 + (n%10);
            n /= 10;
        }
        //cout << reverse << "\n";
        return reverse;
    }
    int mirrorDistance(int n) {
        int revert = (n < 10) ? n : reverseInt(n);
        return abs(revert-n);
    }
};