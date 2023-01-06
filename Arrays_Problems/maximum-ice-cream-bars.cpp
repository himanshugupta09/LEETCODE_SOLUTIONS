class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int  maxIce = 0;

        sort(costs.begin(),costs.end());

        int i=0;
        while(i < costs.size() && coins > 0)
        {
            if(costs[i] <= coins)
            {
                coins -= costs[i];
                i++;
                maxIce++;

            }
            else
            {
                i++;
            }
        }

        return maxIce;

    }
};
