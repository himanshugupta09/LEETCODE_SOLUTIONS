#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static constexpr long long MOD = 1000000007LL;

    vector<long long> total;
    vector<long long> squares;
    vector<long long> lazy;

    void apply(int node, int left, int right, long long val) {
        long long length = right - left + 1;

        // (x + val)^2 = x^2 + 2*val*x + val^2
        squares[node] = (squares[node]
                         + 2 * val * total[node]
                         + val * val * length) % MOD;

        total[node] = (total[node] + val * length) % MOD;

        lazy[node] += val;
    }

    void push(int node, int left, int right) {
        if (lazy[node] == 0 || left == right) {
            return;
        }

        int mid = (left + right) / 2;
        long long val = lazy[node];

        apply(node * 2, left, mid, val);
        apply(node * 2 + 1, mid + 1, right, val);

        lazy[node] = 0;
    }

    void update(int node, int left, int right, int ql, int qr) {
        if (ql <= left && right <= qr) {
            apply(node, left, right, 1);
            return;
        }

        push(node, left, right);
        int mid = (left + right) / 2;

        if (ql <= mid) {
            update(node * 2, left, mid, ql, qr);
        }

        if (qr > mid) {
            update(node * 2 + 1, mid + 1, right, ql, qr);
        }

        total[node] = (total[node * 2] + total[node * 2 + 1]) % MOD;
        squares[node] = (squares[node * 2] + squares[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(const vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        // Segment tree stores sum and sum of squares.
        int size = 4 * n;
        total.assign(size, 0);
        squares.assign(size, 0);
        lazy.assign(size, 0);

        unordered_map<int, int> last_seen;
        long long ans = 0;

        for (int r = 0; r < n; ++r) {
            int x = nums[r];
            int prev = -1;
            auto it = last_seen.find(x);
            if (it != last_seen.end()) {
                prev = it->second;
            }

            // New distinct element for these starting indices.
            update(1, 0, n - 1, prev + 1, r);

            // Sum of squared distinct counts for subarrays ending at r.
            ans = (ans + squares[1]) % MOD;

            last_seen[x] = r;
        }

        return static_cast<int>(ans);
    }
};

