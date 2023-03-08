class Solution {
public:

    long long  getHours(vector<int>&piles,int mid)
    {
        long long need = 0;
        for(int i=0;i<piles.size();i++)
        {
            int htop = ceil(piles[i]/(double)mid);
            need += htop;
        }
        return need;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int lo = 1;
        int hi = *(max_element(piles.begin(),piles.end()));
        int res = -1;
        while(lo <= hi)
        {
            int mid = lo+(hi-lo)/2;
            long long needs = getHours(piles,mid);
            
            if(needs <= h)
            {
                res = mid;
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }

        return lo;
        
    }
};
