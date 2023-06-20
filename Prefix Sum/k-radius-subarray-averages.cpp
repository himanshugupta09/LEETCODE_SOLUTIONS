class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k == 0)
        {
            return nums;
        }
        vector<long long>ps(n+1);

        ps[0] = nums[0];

        for(int i=0;i<n;i++)
        {
            ps[i+1] = ps[i] + nums[i];
        }
        //int n = nums.size();

        

        vector<int>res(n,-1);

        if(2*k+1 > n)
        {
            return res;
        }

        for(int i=k;i<(n-k);i++)
        {
            int lb = i-k;
            int rb = i+k;

            long long sbs = ps[rb+1] - ps[lb];

            res[i] = sbs/(2*k+1);
        }
        return res;


    }
};
