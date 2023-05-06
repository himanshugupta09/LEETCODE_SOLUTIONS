class Solution {
public:

    int binarySearch(vector<int>& nums,int tar)
    {
        int l = 0,r = nums.size()-1;

        while(l <= r)
        {
            int md = l + (r-l)/2;
            if(nums[md] <= tar)
            {
                l = md+1;

            }
            else
            {
                r = md-1;
            }
        }
        return l;
    }

    int numSubseq(vector<int>& nums, int target) {
        int m = 1e9+7;
        sort(nums.begin(),nums.end());
        int n = nums.size();
         vector<int>po(n);
        
        po[0] = 1;

        for(int i=1;i<n;i++)
        {
            po[i] = (po[i-1]*2)%m;
        }
        int res = 0;

        for(int i=0;i<n;i++)
        {
            int r = binarySearch(nums,target-nums[i])-1;

            if(r >= i)
            {
                res += po[r-i];
                res %= m;
            }
        }
        return res;


    }
};
