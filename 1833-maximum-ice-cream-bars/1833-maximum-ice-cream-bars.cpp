class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        long long int max_price = *max_element(costs.begin(),costs.end());
        vector<long long int>counters(max_price+1,0);
        for(auto num:costs){
            counters[num]++;
        }
        long long int res = 0;
        
        long long int i = 1;
        while(coins > 0 && i <= max_price)
        {
            if(i*counters[i] <= coins)
            {
                coins -= i*counters[i];
                res += counters[i];
                i++;
            }
            else
            {
                int canBuy = min(counters[i], coins / i);
                res += canBuy;
                coins -= canBuy * i;
                i++;
            }

        }
        return res;
    }
};