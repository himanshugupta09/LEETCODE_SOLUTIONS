class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>res;

        int sm = k;

        int n = num.size();

        int i = n;

        while(--i >= 0 || sm > 0)
        {
            if(i>=0)
            {
                sm += num[i];
            }
            res.push_back(sm%10);
            sm/=10;

        }
        reverse(res.begin(),res.end());

        return res;
        

       

        



    }
};
