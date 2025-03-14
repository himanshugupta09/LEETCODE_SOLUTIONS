class Solution {
public:
    bool canAllocate(vector<int>&candies,long long k,int num)
    {
        long long int maxi = 0;
        for(int i=0;i<candies.size();i++)
        {
            maxi += candies[i]/num;
        }
        return maxi >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        int maxi = 0;
        int left = 0;
        for(int i:candies)
        {
            maxi = max(maxi,i);
        }
        int right = maxi;
        while(left < right)
        {
            int mid = (left+right+1)/2;
            if(canAllocate(candies,k,mid))
            {
                left = mid;
            }
            else
            {
                right = mid-1;
            }
        }
        return left;
    }
};