class Solution {
public:
    int getNumofBoq(int mid,int k,vector<int>&bloom)
    {
        int numofBoqs = 0;
        int cnt = 0;
        for(auto i:bloom)
        {
            if(i <= mid)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            if(cnt == k)
            {
                numofBoqs++;
                cnt = 0;
            }
        }
        return numofBoqs;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int st = 0;
        int en = *max_element(bloomDay.begin(),bloomDay.end());
        int res = -1;
        
        while(st <= en)
        {
            int mid = (st+en)/2;
            int boqs = getNumofBoq(mid,k,bloomDay);
            if(boqs >= m)
            {
                res = mid;
                en = mid-1;
            }
            else
            {
                st = mid+1;
            }
        }
        return res;
        
    }
};
