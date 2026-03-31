class Solution {
public:
    bool canShip(vector<int>&weights,int maxLimit,int days)
    {
        int countD = 1;
        int weightSum = 0;
        int n = weights.size();
        for(int i=0;i<n;i++)
        {
            if(weightSum + weights[i] <= maxLimit)
            {
                weightSum += weights[i];
            }
            else
            {
                weightSum = weights[i];
                countD++;
            }
        }
        return countD <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);

        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(canShip(weights,mid,days))
            {
                ans = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return ans;
    }
};