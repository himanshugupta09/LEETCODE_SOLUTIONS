class Solution {
public:
    int candy(vector<int>& ratings) {

        
        int n  = ratings.size();
        vector<int>can(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                can[i]  = can[i-1]+1;
            }
        }
        int sum = can[n-1];
        for(int i= n-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                can[i] = max(can[i],(can[i+1]+1));
            }
            sum  += can[i];
        }
        return sum;
        
    }
};