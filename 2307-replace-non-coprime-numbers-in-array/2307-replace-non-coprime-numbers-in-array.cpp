class Solution {
public:
    int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
        unsigned shift = __builtin_ctz(a | b);
        a >>= __builtin_ctz(a);
        do {
            b >>= __builtin_ctz(b);
            if (a > b)
                swap(a, b);
            b -= a;
        } while (b);
        return a << shift;
    }

    int lcm (int a, int b) {
        return a / gcd(a, b) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>res;
        //deque<int>dq;
        for (int num : nums) {
            while (!res.empty() && gcd(res.back(), num) > 1) {
                num = lcm(res.back(), num);
                res.pop_back();
            }
            res.push_back(num);
        }

        return res;
        
    }
};