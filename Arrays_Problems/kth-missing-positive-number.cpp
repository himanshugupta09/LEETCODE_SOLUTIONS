class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int sz = arr.size();
        int l = 0;
        int hi = sz;

        while(hi > l)
        {
            int md = (l+hi)/2;
            int mis = arr[md]-1 - md;

            if(k <= mis)
            {
                hi = md;

            }
            else
            {
                l = md+1;
            }

        }
        return hi+k;
    }
};
