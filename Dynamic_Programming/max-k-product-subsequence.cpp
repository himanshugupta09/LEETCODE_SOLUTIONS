class Solution {
public:
    int maxProduct(vector<int>& arr, int k) {
        long long NEG = LLONG_MIN;
        long long POS = LLONG_MAX;

        vector<long long> mx(k + 1, NEG);
        vector<long long> mn(k + 1, POS);

        mx[0] = mn[0] = 1;

        for (int x : arr) {
            for (int j = k; j >= 1; j--) {
                if (mx[j - 1] != NEG) {
                    long long a = mx[j - 1] * x;
                    long long b = mn[j - 1] * x;

                    mx[j] = max({mx[j], a, b});
                    mn[j] = min({mn[j], a, b});
                }
            }
        }

        return mx[k];
    }
};
