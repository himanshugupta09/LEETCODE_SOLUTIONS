class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

     vector<int>pw;
     int n = weights.size();
     for(int i=1;i<n;i++)
     {
         pw.push_back(weights[i] + weights[i-1]);
     }

     sort(pw.begin(),pw.end());

        long long res = 0;

        for(int i=0;i<k-1;i++)
        {
            res += pw[n-2-i] - pw[i];
        }
        return res;
    }
};